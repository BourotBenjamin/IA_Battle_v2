#include <cstdlib>
#include <algorithm>
#include "Unit.hpp"
#include <memory>
#include <numeric>
#include "NodeConstructor.h"

//static counter used for unique id creation
int Unit::idCount_=0;

//Method in charge of the initialization of id, position(random), and capacities
void Unit::init_()
{
    id_ = idCount_++;
    this->position_ = Point(
        (std::rand() % (Terrain::getMaxX() * 2)) - Terrain::getMaxX(),
        (std::rand() % (Terrain::getMaxY() * 2)) - Terrain::getMaxY());
    this->capacities_.reserve(7);
    this->capacities_.push_back(std::unique_ptr<Capacity>(new SpeedCapacity()));
    this->capacities_.push_back(std::unique_ptr<Capacity>(new LifeCapacity()));
    this->capacities_.push_back(std::unique_ptr<Capacity>(new ArmorCapacity()));
    this->capacities_.push_back(std::unique_ptr<Capacity>(new RegenCapacity()));
    this->capacities_.push_back(std::unique_ptr<Capacity>(new DamageCapacity()));
    this->capacities_.push_back(std::unique_ptr<Capacity>(new RangeCapacity()));
    this->capacities_.push_back(std::unique_ptr<Capacity>(new FirerateCapacity()));
}

void Unit::InitializeOpenGL()
{

    glGenBuffers(1, &cubeVBO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_cubeVertices), g_cubeVertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &cubeEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_cubeIndices), g_cubeIndices, GL_STATIC_DRAW);
}

//Constructor : global level will be randomly dispatched among the capacities
Unit::Unit(int globalLevel)
{
    init_();
	std::string ia = std::string("?mDOPU<C5U?C2LDOPU<C4U?C6U<V0.001!ALDOPU!EBO!EBO!MBO ");
	//std::string ia = NodeConstructor::generateRandomTreeElementCode(0);
	this->iaCode_ = ia;
	tree = std::shared_ptr<TreeElement>((TreeElement*)NodeConstructor::create(&ia));
    while(globalLevel--) {
        this->capacities_[std::rand()%this->capacities_.size()]->upgrade();
    }
}


//Constructor from the code of AI and the level of the different capacities
Unit::Unit(std::string iaCode, int speedLevel, int lifeLevel, int armorLevel, int regenLevel, int damageLevel, int rangeLevel, int firerateLevel)
{
    init_();
    this->iaCode_ = iaCode;
	tree = std::shared_ptr<TreeElement>((TreeElement*)NodeConstructor::create(&iaCode));
    getSpeed().upgrade(speedLevel);
    getLife().upgrade(lifeLevel);
    getArmor().upgrade(armorLevel);
    getRegen().upgrade(regenLevel);
    getDamage().upgrade(damageLevel);
    getRange().upgrade(rangeLevel);
    getFirerate().upgrade(firerateLevel);
}


//Constructor from the code of AI and the level of the 7 capacities
Unit::Unit(std::string iaCode, std::vector<int>& levels)
{
	init_();
	this->iaCode_ = iaCode;
	tree = std::shared_ptr<TreeElement>((TreeElement*)NodeConstructor::create(&iaCode_));
	this->iaCode_ = iaCode;
    for(unsigned int i = 0; i < levels.size() && i < capacities_.size(); ++i) {
        capacities_[i]->upgrade(levels[i]);
    }
}


//Copy constructor
Unit::Unit(const Unit& unit)
{
	init_();
	this->iaCode_ = unit.iaCode_;
	tree = std::shared_ptr<TreeElement>(std::move((TreeElement*)NodeConstructor::create(&iaCode_)));
	this->iaCode_ = unit.iaCode_;
    for(unsigned int i = 0;  i < capacities_.size(); ++i) {
        capacities_[i]->upgrade(unit.capacities_[i]->getLevel());
    }
}


//Swap the content of the parameter and the current object
void Unit::swap(Unit& unit)
{
    std::swap(capacities_, unit.capacities_);
    std::swap(iaCode_, unit.iaCode_);
    std::swap(position_, unit.position_);
	std::swap(id_, unit.id_);
	tree = std::shared_ptr<TreeElement>((TreeElement*)NodeConstructor::create(&this->iaCode_));
	iaCode_ = unit.iaCode_;
}


//Assignment operator overload
Unit& Unit::operator=(Unit unit)
{
    swap(unit);
    return *this;
}


//Provide the global level of the unit (I.E. the sum of all capacities levels)
int Unit::getLevel()const
{
    return std::accumulate(capacities_.begin(), capacities_.end(),0,
    [](int& a,  const std::unique_ptr<Capacity>& b) {
        return a+b->getLevel();
    });
}


//Refresh the capacities of the unit, most often used at the beginning of fight turn.
//Reduce the cooldown of the firerate, and apply the regen on the life
void Unit::refresh()
{
    getLife().takeRegen(getRegen().getValue());
    getFirerate().reload();
}


//Make the unit shot if it is possible. In this case, the cooldown
//is set to maximum value and the method return true, otherwise, it return false.
bool Unit::shoot()
{
    if(getFirerate().canShoot()) {
        getFirerate().shoot();
        return true;
    }
    return false;
}


//Apply the damages to the unit, by first reducing them by the armor,
//then apply it to the life.
void Unit::takeDamage(double value)
{
    getLife().takeDamage(value);
}


//Provide a randomly muteted version of the current unit
Unit Unit::mutate()const
{
    int index = std::rand()%7;
    std::vector<int> levels(7);
    for(int i = 0; i < 7; ++i) {
        levels[i] = capacities_[i]->getLevel();
    }
    while(levels[index]==0) {
        index = std::rand()%7;
    }
    int index2 = std::rand()%7;
    while(index == index2) {
        index2 = std::rand()%7;
    }
    levels[index]--;
    levels[index2]++;
    return Unit(iaCode_,levels);
}


//Star operator overloading, providing a random crossing of the current
//unit and the one provided in parameter.
Unit Unit::operator*(const Unit& unit)const
{
    std::vector<int> maxLevels(7);
    for(int i = 0; i < 7; ++i) {
        maxLevels[i] = std::max<int>(capacities_[i]->getLevel(), unit.getCapacity(i)->getLevel());
    }
    int gA = this->getLevel();
    int gB = unit.getLevel();
    int global = gA;
    if(gA!=gB)
        global = std::min<int>(gA, gB)+std::rand()%std::abs(gA-gB);
    std::vector<int> levels(7,0);
    while(global) {
        int index = std::rand()%7;
        if(levels[index]<maxLevels[index]) {
            levels[index]++;
            global--;
        }
    }
	std::string ia;
	if (std::rand() % 2)
	{
		ia = std::string(iaCode_);
		std::string oldIaPart = getRandomIATreeSonCode();
		size_t start_pos = ia.find(oldIaPart);
		if (start_pos != std::string::npos)
		{
			ia.replace(start_pos, oldIaPart.size(), unit.getRandomIATreeSonCode());
		}
	}
	else
	{
		ia = std::string(unit.getIACode());
		std::string oldIaPart = unit.getRandomIATreeSonCode();
		size_t start_pos = ia.find(oldIaPart);
		if (start_pos != std::string::npos)
		{
			ia.replace(start_pos, oldIaPart.size(), getRandomIATreeSonCode());
		}
	}
    return Unit(ia,levels);
}


//Save the current unit in the given output stream.
void Unit::save(std::ostream& out)const
{
    std::for_each(capacities_.begin(), capacities_.end(),  [&out](const std::unique_ptr<Capacity>& c) {
        out<<c->getLevel()<<" ";
    });
    out<<iaCode_<<std::endl;
}


//Load a unit from the input stream
Unit Unit::load(std::istream& in)
{
    in.exceptions(std::istream::failbit | std::istream::eofbit);
    std::vector<int> levels(7);
    std::string iacode;
    std::for_each(levels.begin(), levels.end(), [&in](int& level) {
        in >> level;
    });
    in >> iacode;
    return Unit(iacode, levels);
}


void Unit::draw(GLuint program)
{
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);

    GLint positionLocation = glGetAttribLocation(program, "a_position");
    glEnableVertexAttribArray(positionLocation);
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

    GLint colorLocation = glGetUniformLocation(program, "u_color");
    glUniform4f(colorLocation, this->myColor.RedValue, this->myColor.GreenValue, this->myColor.BlueValue, 1.0f);

    if (this->isAnimating && !this->BlockAnimation)
    {
        this->moveToPosition(this->NextPosition_,0.01f);
        consumeSpeed += 0.01f;
        if (consumeSpeed >= this->getSpeed().getValue())
            this->isAnimating = false;
    }

    GLint offsetLocation = glGetUniformLocation(program, "u_offset");
    glUniform3f(offsetLocation, this->position_.getX(), this->position_.getY(), 0.0f);
    glDrawArrays(GL_TRIANGLES, 0, sizeof(g_cubeVertices));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
    glDrawElements(GL_TRIANGLES, sizeof(g_cubeIndices), GL_UNSIGNED_SHORT, nullptr);
}

std::string Unit::getRandomIATreeSonCode()const
{
	return tree->getRandomSonCode(rand() % 5);
}

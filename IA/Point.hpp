#ifndef _POINT_HPP_
#define _POINT_HPP_
#include <cmath>
#include <ostream>
#include <iomanip>

//Class representing a D point
class Point {
private:
    double x_;//X coordinate
    double y_;//Y coordinate

public:
    //Natural constructor
    Point(double x=0, double y=0):x_(x), y_(y) {}


    ////////////////////////
    //getters
    ////////////////////////
    double getX()const
    {
        return x_;
    }

    double getY()const
    {
        return y_;
    }

    ///////////////////////
    //setters
    ///////////////////////
    void setX(double x)
    {
        x_ = x;
    }

    void setY(double y)
    {
        y_ = y;
    }

    /////////////////////////////////////
    //arithmetic operators overloading
    /////////////////////////////////////
    bool operator==(const Point& p)
    {
        return !(*this != p);
    }

    bool operator!=(const Point& p)
    {
        if (x_ != p.x_ || y_ != p.y_)
            return true;
        return false;
    }

    Point& operator+=(const Point& p)
    {
        x_+=p.x_;
        y_+=p.y_;
        return *this;
    }

    Point& operator-=(const Point& p)
    {
        x_-=p.x_;
        y_-=p.y_;
        return *this;
    }

    Point& operator*=(double s)
    {
        x_*=s;
        y_*=s;
        return *this;
    }

    Point& operator/=(double s)
    {
        return *this *= (1.0/s);
    }

    Point operator+(Point p)const
    {
        return p+=*this;
    }

    Point operator-(const Point& p)const
    {
        return Point(*this)-=p;
    }

    Point operator*(double s)const
    {
        return Point(*this)*=s;
    }

    Point operator/(double s)const
    {
        return Point(*this)/=s;
    }

    Point operator-()const
    {
        return Point(-x_, -y_);
    }

    //Compute the dot product with another point
    double dot(const Point& p)const
    {
        return x_*p.x_+y_*p.y_;
    }

    //Compute the norm of the point
    double norm()const
    {
        return sqrt(this->dot(*this));
    }

    //Compute the Euclidian distance between this point nd another
    double distance(Point p)const
    {
        p-=*this;
        return p.norm();
    }

    //Traslate this point in direction of the one in parameter:
    // if distance is bigger than max, translate to max units
    // otherwise translate to the position p
    void moveTo(const Point& p, double max)
    {
        Point vec = p - *this;
        double d = vec.norm();
        if(d <= max) {
            (*this)+=vec;
        } else {
            (*this)+= (vec*(max/d));
        }
    }
};

//Star operator overloading. Case  Scalar*Point
inline Point operator*(double s, Point p )
{
    return p*=s;
}

//Shift operator overloading, printing the point in the output stream.
inline std::ostream& operator<<(std::ostream& out, const Point& p)
{
    out<<std::fixed<<std::setprecision(1)<<"("<<p.getX()<<","<<p.getY()<<")";
    return out;
}

#endif
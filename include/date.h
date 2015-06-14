#ifndef _DATE_H
#define _DATE_H

#include <iostream>

class Date
{
  private:
    int _day=0;
    int _month=0;
    int _year=0;
  
  public:
    Date() = default;
    Date(int day, int month, int year) 
      : _day(day), _month(month), _year(year) {}

    const int& Day() const { return _day; }
    const int& Month() const { return _month; }
    const int& Year() const { return _year; }
    
    int& Day() { return _day; }
    int& Month() { return _month; }
    int& Year() { return _year; } 
    
    bool operator>(const Date& other) const
    {
      if(_year>other._year) return true;
      if(_year<other._year) return false;
      if(_month>other._month) return true;
      if(_month<other._month) return false;
      if(_day>other._day) return true;
      if(_day<other._day) return false;
      return false;
    }

    bool operator<(const Date& other) const
    {
      if(_year<other._year) return true;
      if(_year>other._year) return false;
      if(_month<other._month) return true;
      if(_month>other._month) return false;
      if(_day<other._day) return true;
      if(_day>other._day) return false;
      return false;
    }
    bool operator==(const Date& other) const
    {
      return (_day==other._day && _month==other._month && _year==other._year);
    }

    bool operator!=(const Date& other) const
    {
      
      return (_day!=other._day || _month!=other._month || _year!=other._year ); 
    }

    friend std::ostream& operator<<(std::ostream& out, const Date& date)
    {
      if(out==std::cout)
      {
        if(date._day/10==0) std::cout<<0;
        std::cout<<date._day<<'.';
        if(date._month/10==0) std::cout<<0;
        std::cout<<date._month<<'.'<<date._year<<' ';
      }
      else
      {
        out<<date._day<<','<<date._month<<','<<date._year;
      }
      return out;
    }


};

#endif

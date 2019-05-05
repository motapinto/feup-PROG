#include "date.h"

Date::Date(){
  time_t current_time = time(0);
  tm *time_now = localtime(&current_time);
    
  this->day = time_now->tm_mday;
  this->month = time_now->tm_mon;
  this->year = time_now->tm_year;
}

Date::Date(unsigned int year, unsigned int month,unsigned int day){
    this->year = year;
    this->month = month;
    this->day = day;

    std::string date = getDate();

    checkDate(date);
    this->day = stoi(date.substr(6,2));
    this->month = stoi(date.substr(4,2));
    this->year = stoi(date.substr(0, 4));
}

Date::Date(std::string date){
    checkDate(date);
    this->day = stoi(date.substr(6,2));
    this->month = stoi(date.substr(4,2));
    this->year = stoi(date.substr(0, 4));
}

bool Date::operator > (const Date date){
  if(this->year == date.getYear()){
    if(this->month > date.getMonth()) return true;
    if(this->month < date.getMonth()) return false;

    if(this->day > date.getDay()) return true;
    else return false;
  }

  if(this->year > date.getYear()) return true;

  return false;
}

bool Date::operator >= (const Date date){
  if(*this == date) return true;
  if(*this > date) return true;

  return false;
}

bool Date::operator < (const Date date){
  if(this->year == date.getYear()){
    if(this->month > date.getMonth()) return false;
    if(this->month < date.getMonth()) return true;

    if(this->day < date.getDay()) return true;
    else return false;
  }

  if(this->year < date.getYear()) return true;

  return false;
}

bool Date::operator <= (const Date date){
  if(*this == date) return true;
  if(*this < date) return true;

  return false;

}

bool Date::operator == (const Date date){
  if(this->year != date.getYear()) return false;
  if(this->month != date.getMonth()) return false;
  if(this->day != date.getDay()) return false;

  return true;
}

bool Date::operator != (const Date date){
  if(this->year != date.getYear()) return true;
  if(this->month != date.getMonth()) return true;
  if(this->day != date.getDay()) return true;

  return false;
}

Date Date::operator = (const Date date){
  this->day = date.day;
  this->month = date.month;
  this->year = date.year;

  return *this;
}

void Date::setYear (unsigned int year){
    std::string date;
    this->year = year;

    std::string date = getDate();

    checkDate(date);
    this->day = stoi(date.substr(6,2));
    this->month = stoi(date.substr(4,2));
    this->year = stoi(date.substr(0, 4));
}

void Date::setDay (unsigned int day){
    std::string date;
    this->day = day;

    std::string date = getDate();

    checkDate(date);
    this->day = stoi(date.substr(6,2));
    this->month = stoi(date.substr(4,2));
    this->year = stoi(date.substr(0, 4));
}

void Date::setMonth (unsigned int month){
    std::string date;
    this->month = month;

    std::string date = getDate();

    checkDate(date);
    this->day = stoi(date.substr(6,2));
    this->month = stoi(date.substr(4,2));
    this->year = stoi(date.substr(0, 4));
}

void Date::setDate(std::string date){
    checkDate(date);
    this->day = stoi(date.substr(6,2));
    this->month = stoi(date.substr(4,2));
    this->year = stoi(date.substr(0, 4));
    
}

void Date::setDate (unsigned int year, unsigned int month, unsigned int day){
    
    this->year = year;
    this->month = month;
    this->day = day;

    std::string date = getDate();

    checkDate(date);
    this->day = stoi(date.substr(6,2));
    this->month = stoi(date.substr(4,2));
    this->year = stoi(date.substr(0, 4));
}

unsigned int Date::getYear() const{ 
  return this->year; 
}

unsigned int Date::getMonth() const{ 
  return this->month; 
}

unsigned int Date::getDay() const{ 
  return this->day; 
}

std::string Date::getDate() const{ // returns the date in format "yyyy/mm/dd"
  std::string date;

  std::string date = std::to_string(this->day) + "/" + std::to_string(this->month) + "/" + std::to_string(this->year);

  return date;
}

void Date::show() const{ // shows the date on the screen in format "yyyy/mm/dd"
  std::cout << std::setw(4) << this->year << '/' << std::setw(2) << this->month << '/' << std::setw(2) << this->day << std::endl;
}

unsigned int Date::daysOf(unsigned int month, unsigned int &year) {
  switch (month) {
    case 2:
      if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0)
        return 29;
      else
        return 28;

    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
    case 11:
      return 31;

    case 4:
    case 6:
    case 8:
    case 10:
    case 12:
      return 31;

    default:
      return 0;
  }
  return 0;
}

void Date::checkDate(std::string &date) {
    unsigned int day, month, year;

  if (date.size() == 10 && date.at(2) == '/' && date.at(5) == '/')
  {
        day = stoi(date.substr(0, 2));
        month = stoi(date.substr(3, 2));
        year = stoi(date.substr(5, 4));

        if(this->day >= 1 && this->day <= this->daysOf(this->month, this->year) && 
        this->month >= 1 && this->month <= 12 && 
        this->year >= 1900 && this->year <=3000) 
        { }

        else
        {
            throw new DateException(NULL);
        }
  }

  else 
  {
    throw new DateException(NULL);
  }

}

bool Date::validSet(std::string date) {
    try {
        this->setDate(date);
    }

    catch(DateException) {
        return false;
    }

    catch(const invalid_argument& ia) {
        return false;
    }

    catch (const std::out_of_range& oor) {
        return false;
    }

    catch(...) {
        return false;
    }

    return true;
}

bool Date::validSet(unsigned int year, unsigned int month, unsigned int day) {
    try {
        this->setDate(year, month, day);
    }

    catch(DateException) {
        return false;
    }

    catch(const invalid_argument& ia) {
        return false;
    }

    catch (const std::out_of_range& oor) {
        return false;
    }

    catch(...) {
        return false;
    }

    return true;
}

bool Date::validConstruct(std::string date = "current time") {
    try {
        if(date == "current time")
          new Date();
        else
          new Date(date);
    }

    catch(DateException) {
        return false;
    }

    catch(const invalid_argument& ia) {
        return false;
    }

    catch (const std::out_of_range& oor) {
        return false;
    }

    catch(...) {
        return false;
    }

    return true;
}

bool Date::validConstruct(unsigned int year, unsigned int month, unsigned int day) {
    try {
        new Date(year, month, day);
    }

    catch(DateException) {
        return false;
    }

    catch(const invalid_argument& ia) {
        return false;
    }

    catch (const std::out_of_range& oor) {
        return false;
    }

    catch(...) {
        return false;
    }

    return true;
}
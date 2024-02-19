//
//  User.hpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/9/24.
//

#ifndef User_hpp
#define User_hpp
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "DateTime.hpp"
using namespace std;

enum UPDATE_OPTIONS{
    UPDATE_NAME = 1,
    UPDATE_ROLE,
    UPDATE_ADDRESS,
    UPDATE_PHONE,
    UPDATE_EMAIL,
};
enum DELETE_OPTIONS{
    DELETE_NAME = 1,
    DELETE_ROLE,
    DELETE_ADDRESS,
    DELETE_PHONE,
    DELETE_EMAIL,
};

class User{

public:
    User();
    
    User(int id, const string&role, const string& username, const string& password,const DateTime& signIn_dt, const DateTime& signOut_dt, const string& firstName, const string& lastName, const string& address, const string& city, const string& state, const string& zip, const string& phone, const string& email);
    
//    User(string password, string username);
    
    User (const string& firstName,const string& lastName,const string& phone,const string& email,const string&password); //THIS IS FOR CREATE ACCOUNT CONSTRUCTOR
    ~User();
    
    void setId(int id);
    void setRole(string role);
    void setUsername(string user);
    void setPassword(string pass);
    void setFirstname(string firstName);
    void setLastname(string lastName);
    void setAddress(string addy);
    void setCity(string city);
    void setState(string state);
    void setZip(string zip);
    void setPhone(string phone);
    void setEmail(string email);
    void setSignIn_dt(const DateTime& signIn_dt);
    void setSignOut_dt(const DateTime& signOut_dt);
    

    int getiId() const;
    string getRole() const;
    string getUsername() const;
    string getPassword() const;
    string getFirstName() const;
    string getLastName() const;
    string getAddress() const;
    string getCity() const;
    string getState() const;
    string getZip() const;
    string getPhone() const;
    string getEmail() const;
    DateTime getSignInDt()const;
    DateTime getSignOutDt()const;
    
    bool operator==(const User& other) const;
    bool comparePassword(const string& oldPassword)const;
    void updateProfile(int option,User& user);
    void updateUser(const User& other); /// THIS IS TO UPDATE WITH TEMPUSER
    void removeInfo(int option);
    void clear();
//    void deleteAccount(User&user);
    
    bool getSignedIn() const;
    bool getSignedOut() const;
    void setSignedIn();
    void setSignedOut();
    
    User& operator=(const User& other) {
          if (this != &other) { // Avoid self-assignment
              // Set all member variables of current object to the values of other object
              this->id = other.id;
              this->role = other.role;
              this->username = other.username;
              this->password = other.password;
              this->signIn_dt = other.signIn_dt;
              this->signOut_dt = other.signOut_dt;
              this->firstName = other.firstName;
              this->lastName = other.lastName;
              this->address = other.address;
              this->city = other.city;
              this->state = other.state;
              this->zip = other.zip;
              this->phone = other.phone;
              this->email = other.email;
              this->signedIn = other.signedIn;
              this->signedOut = other.signedOut;
          }
          return *this; // Return the current object
      }
    
private:
    int id;
    string role, username, password, firstName,lastName, address, city, state, zip, phone, email;
    DateTime signIn_dt, signOut_dt;
    
//    string signInDt, signOutDt;
    bool signedIn;
    bool signedOut;
        
};

#endif /* User_hpp */

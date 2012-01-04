//
// pedsim - A microscopic pedestrian simulation system. 
// Copyright (c) 2003 - 2004 by Christian Gloor
//                              
// You can redistribute and/or modify this program under the terms of
// the GNU General Public License.  See copying.txt for details.
// 

#ifndef _agent_h_
#define _agent_h_ 1

//#include <QApplication>
#include <QGraphicsItem>
#include <QQueue>

#include <iostream>
//#include <vector>

#include "vector.h"


using namespace std;

// ----------------------------------------------------
// Name: Tagent
//!Description: Class that descripts an agent object
//!Introduced: chgloor Dec 26, 2003
// ----------------------------------------------------
class Tagent {
 private:
  int id;                                           ///< agent number
  double x;                                         ///< current position of the agent 
  double y;                                         ///< current position of the agent 
  double z;                                         ///< current position of the agent 
  double ax;                                        ///< current acceleration of the agent
  double ay;                                        ///< current acceleration of the agent
  double az;                                        ///< current acceleration of the agent
  double vx;                                        ///< velocity of the agent
  double vy;                                        ///< velocity of the agent
  double vz;                                        ///< velocity of the agent
  int type;                                         
  
 public:
  Tagent();
  void move(long systemtime);                       ///< This is the main function of the agent, here, all the dynamics takes place
  void setPosition(double px, double py, double pz);///< set the agents position (to beam the agent)
  void setType(int t) {type = t; };                 ///< sets the agent type
  int getid() { return id; };                       ///< returns the agents id
  int gettype() { return type; };                   ///< returns the agents type
  double getx() { return x; };                      ///< returns the agents x position
  double gety() { return y; };                      ///< returns the agents y position
  double getz() { return z; };                      ///< returns the agents z position
  double getax() { return ax; };                    ///< returns the agents x acceleration
  double getay() { return ay; };                    ///< returns the agents y acceleration
  double getaz() { return az; };                    ///< returns the agents z acceleration
  double getvx() { return vx; };                    ///< returns the agents vx velocity
  double getvy() { return vy; };                    ///< returns the agents vy velocity
  double getvz() { return vz; };                    ///< returns the agents vz velocity
  void print() {cout << "agent " << id << ": " << x << "/" << y << "/" << z << endl; }; ///< prints the agents state (simple) to stdout
  QGraphicsRectItem *rect;

  QQueue<Tvector> destinations;                      ///< coordinates of the next destinations
  Tvector destination;                               ///< coordinates of the next destination
  bool hasreacheddestination;                        ///< true if it ahs reached its destination
};

/// A container for the agents. Defined here because some methods inside the Tagent class iterate over this container
#define AgentContainer vector<Tagent>
/// A container iterator for the agents. Defined here because some methods inside the Tagent class iterate over this container
#define AgentIterator vector<Tagent>::iterator


#endif

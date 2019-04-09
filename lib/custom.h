//
// Created by Vladislav Molodtsov on 2019-03-31.
//

#ifndef __CUSTOM_H__
#define __CUSTOM_H__
#include "geometry.h"

/* --------------------- Custom classes ------------------------ */

/*
 *
 * You can change these on your own.
 *
 */
namespace message {


/*
 *
 * Output class for transmission to Vision
 *
*/
struct Receive {
  float x = 0, y = 0;

  void Print();
};

/*
 *
 * Input class for receiving from Vision
 *
*/
struct Send {
  Point p;
  void Print();
};

} /* namespace message */

#endif /* __CUSTOM_H__ */

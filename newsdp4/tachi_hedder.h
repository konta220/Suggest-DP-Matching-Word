/*
 * tachi_hedder.h
 *
 *  Created on: 2014/01/24
 *      Author: cs12051
 */

#ifndef TACHI_HEDDER_H_
#define TACHI_HEDDER_H_
#include "mainhedder.h"

typedef struct cost {
	int mincost;
	int leftdir;
	int updir;
} Costs;

typedef struct ranking {
	int patternnunber;
	int costs;
} RECORD;

int table[MAXcharsize][MAXcharsize];
Costs cost[MAXcharsize][MAXcharsize];

RECORD costRank[RANKSIZE];

#endif /* TACHI_HEDDER_H_ */

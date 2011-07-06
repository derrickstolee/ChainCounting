/*
 * ChainManager.hpp
 *
 *  Created on: Jun 22, 2011
 *      Author: derrickstolee
 */

#ifndef CHAINMANAGER_HPP_
#define CHAINMANAGER_HPP_

#include "SearchManager.hpp"

class ChainManager: public SearchManager
{
protected:

	int k;
	int j;
	int minN;
	int maxN;
	int a;
	int maxSum;

	int cur_pos;
	int num_parameters;
	int* parameters;

	int param_sum;

	char* found_numbers;

	/**
	 * this is the function that will be called.
	 */
	int (*chainFunct)(int*);

public:

	ChainManager(int k, int j, int minN, int maxN, int a, int maxSum);

	virtual ~ChainManager();

	/**
	 * pushNext -- deepen the search to the next child
	 * 	of the current node.
	 *
	 * @return the label for the new node. -1 if none.
	 */
	virtual LONG_T pushNext();

	/**
	 * pushTo -- deepen the search to the specified child
	 * 	of the current node.
	 *
	 * @param child the specified label for the new node
	 * @return the label for the new node. -1 if none, or failed.
	 */
	virtual LONG_T pushTo(LONG_T child);

	/**
	 * pop -- remove the current node and move up the tree.
	 *
	 * @return the label of the node after the pop.
	 * 		This return value is used for validation purposes
	 * 		to check proper implementation of push*() and pop().
	 */
	virtual LONG_T pop();

	/**
	 * prune -- Perform a check to see if this node should be pruned.
	 *
	 * @return 0 if no prune should occur, 1 if prune should occur.
	 */
	virtual int prune();

	/**
	 * isSolution -- Perform a check to see if a solution exists
	 * 		at this point.
	 *
	 * @return 0 if no solution is found, 1 if a solution is found.
	 */
	virtual int isSolution();

	/**
	 * writeSolution -- create a buffer that contains a
	 * 	description of the solution.
	 *
	 * Solution strings start with S.
	 *
	 * @return a string of data allocated with malloc().
	 * 	It will be deleted using free().
	 */
	virtual char* writeSolution();

	/**
	 * writeStatistics -- create a buffer that contains a
	 * 	description of the solution.
	 *
	 * Statistics take the following format in each line:
	 *
	 * T [TYPE] [ID] [VALUE]
	 *
	 * @return a string of data allocated with malloc().
	 * 	It will be deleted using free().
	 */
	virtual char* writeStatistics();


	bool isNumberFound(int num);

	bool setNumberFound(int num);

};

#endif /* CHAINMANAGER_HPP_ */

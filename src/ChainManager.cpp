/*
 * ChainManager.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: derrickstolee
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ChainManager.hpp"
#include "chainfunctions.hpp"

ChainManager::ChainManager(int k, int j, int minN, int maxN, int a, int maxSum)
{
	this->k = k;
	this->j = j;

	switch ( k )
	{
	case 2:
		this->chainFunct = &chainK2N000;
		break;

	case 3:
		this->chainFunct = &chainK3N000;
		break;

	case 4:
		switch ( j )
		{
		case 0:
			this->chainFunct = &chainK4N000;
			break;

		case 1:
			this->chainFunct = &chainK4N001;
			break;

		case 2:
			this->chainFunct = &chainK4N002;
			break;
		}
		break;

	case 5:
		switch ( j )
		{
		case 0:
			this->chainFunct = &chainK5N000;
			break;

		case 1:
			this->chainFunct = &chainK5N001;
			break;

		case 2:
			this->chainFunct = &chainK5N002;
			break;

		case 3:
			this->chainFunct = &chainK5N003;
			break;

		case 4:
			this->chainFunct = &chainK5N004;
			break;

		default:
			printf("--OUT OF RANGE FOR K = %d... 0-4\n", k);
			exit(1);
		}
		break;

	case 6:
		switch ( j )
		{
		case 0:
			this->chainFunct = &chainK6N000;
			break;

		case 1:
			this->chainFunct = &chainK6N001;
			break;

		case 2:
			this->chainFunct = &chainK6N002;
			break;

		case 3:
			this->chainFunct = &chainK6N003;
			break;

		case 4:
			this->chainFunct = &chainK6N004;
			break;

		case 5:
			this->chainFunct = &chainK6N005;
			break;

		case 6:
			this->chainFunct = &chainK6N006;
			break;

		case 7:
			this->chainFunct = &chainK6N007;
			break;

		case 8:
			this->chainFunct = &chainK6N008;
			break;

		case 9:
			this->chainFunct = &chainK6N009;
			break;

		case 10:
			this->chainFunct = &chainK6N010;
			break;

		case 11:
			this->chainFunct = &chainK6N011;
			break;

		case 12:
			this->chainFunct = &chainK6N012;
			break;

		case 13:
			this->chainFunct = &chainK6N013;
			break;

		case 14:
			this->chainFunct = &chainK6N014;
			break;

		case 15:
			this->chainFunct = &chainK6N015;
			break;

		case 16:
			this->chainFunct = &chainK6N016;
			break;

		case 17:
			this->chainFunct = &chainK6N017;
			break;

		default:
			printf("--OUT OF RANGE FOR K = %d... 0-17\n", k);
			exit(1);
		}
		break;

	}

	if ( (minN % 2) == 1 )
	{
		this->minN = minN - 1;
	}
	else
	{
		this->minN = minN;
	}

	this->maxN = maxN;
	this->a = a;
	this->maxSum = maxSum;

	this->num_parameters = 2 * k + 2;
	this->parameters = (int*) malloc(this->num_parameters * sizeof(int));

	for ( int i = 0; i < this->num_parameters; i++ )
	{
		this->parameters[i] = 1;
	}
	this->parameters[0] = 0;
	this->parameters[k + 1] = 0;

	this->param_sum = this->num_parameters - 2;

	int found_size = (this->maxN - this->minN + 6) / 6;
	this->found_numbers = (char*) malloc(found_size);

	bzero(this->found_numbers, found_size);

	this->cur_pos = 0;
}

ChainManager::~ChainManager()
{
	free(this->parameters);
	free(this->found_numbers);
}

/**
 * pushNext -- deepen the search to the next child
 * 	of the current node.
 *
 * @return the label for the new node. -1 if none.
 */
LONG_T ChainManager::pushNext()
{
	if ( this->cur_pos >= this->num_parameters )
	{
		return -1;
	}

	LONG_T child = 0;
	if ( this->stack.size() > 0 )
	{
		SearchNode* parent = this->stack.back();
		child = parent->curChild + 1;
	}
	else
	{
		child = this->root->curChild + 1;
	}

	if ( child < this->parameters[this->cur_pos] )
	{
		child = this->parameters[this->cur_pos];
	}

	return this->pushTo(child);
}

/**
 * pushTo -- deepen the search to the specified child
 * 	of the current node.
 *
 * @param child the specified label for the new node
 * @return the label for the new node. -1 if none, or failed.
 */
LONG_T ChainManager::pushTo(LONG_T child)
{
	if ( this->cur_pos >= this->num_parameters )
	{
		return -1;
	}

	if ( child < 0 || child > this->a )
	{
		return -1;
	}

	//	for ( int i = 0; i < cur_pos; i++ )
	//		printf(" ");
	//	printf("%d\n", (int) child);

	this->param_sum = this->param_sum - this->parameters[this->cur_pos];
	this->parameters[this->cur_pos] = (int) child;
	this->param_sum = this->param_sum + this->parameters[this->cur_pos];

	this->cur_pos = this->cur_pos + 1;

	if ( this->stack.size() > 0 )
	{
		SearchNode* parent = this->stack.back();
		parent->curChild = child;
	}
	else
	{
		this->root->curChild = child;
	}

	this->stack.push_back(new SearchNode(child));

	return child;
}

/**
 * pop -- remove the current node and move up the tree.
 *
 * @return the label of the node after the pop.
 * 		This return value is used for validation purposes
 * 		to check proper implementation of push*() and pop().
 */
LONG_T ChainManager::pop()
{
	this->cur_pos = this->cur_pos - 1;

	int val = this->parameters[this->cur_pos];

	this->param_sum = this->param_sum - val;

	this->parameters[this->cur_pos] = 1;

	if ( this->cur_pos == 0 || this->cur_pos == this->k + 1 )
	{
		this->parameters[this->cur_pos] = 0;
	}

	this->param_sum = this->param_sum + this->parameters[this->cur_pos];

	if ( this->stack.size() > 0 )
	{
		SearchNode* node = this->stack.back();
		this->stack.pop_back();

		delete node;
	}

	return val;
}

/**
 * prune -- Perform a check to see if this node should be pruned.
 *
 * @return 0 if no prune should occur, 1 if prune should occur.
 */
int ChainManager::prune()
{
	if ( this->cur_pos > this->num_parameters )
	{
		return 1;
	}
	else if ( this->param_sum > this->maxSum )
	{
		return 1;
	}
	else if ( this->chainFunct(this->parameters) > this->maxN )
	{
		return 1;
	}

	return 0;
}

/**
 * isSolution -- Perform a check to see if a solution exists
 * 		at this point.
 *
 * @return 0 if no solution is found, 1 if a solution is found.
 */
int ChainManager::isSolution()
{
	if ( this->cur_pos >= this->num_parameters )
	{
		int num_chains = this->chainFunct(this->parameters);
		//		printf("%d\n", num_chains);
		this->setNumberFound(num_chains);
	}

	return 0;
}

/**
 * writeSolution -- create a buffer that contains a
 * 	description of the solution.
 *
 * Solution strings start with S.
 *
 * @return a string of data allocated with malloc().
 * 	It will be deleted using free().
 */
char* ChainManager::writeSolution()
{
	return "";
}

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
char* ChainManager::writeStatistics()
{
	/* Here, write the statistics for MISSING NUMBERS */
	if ( (this->deepeningMode & DEEPEN_GENERATE) == 0 )
	{
		printf("S 0 0\nMISSING LIST: \n--\t");
		int num_missing = 0;
		for ( int i = this->minN + 1; i < this->maxN; i += 2 )
		{
			if ( this->isNumberFound(i) == false )
			{
				printf("%10d ", i);
				num_missing++;

				if ( (num_missing % 10) == 0 )
				{
					printf("\n--\t");
				}
			}
		}
		printf("\n");
	}

	return this->writeBaseStats();
}

bool ChainManager::isNumberFound(int num)
{
	if ( num <= this->minN || num > this->maxN )
	{
		return false;
	}

	if ( (num % 2) == 0 )
	{
		return false;
	}

	int pos = num - this->minN;
	int odd = (pos - 1) / 2;

	int bit = odd % 6;
	int byte = odd / 6;

	return (((this->found_numbers[byte]) & (1 << bit)) != 0);
}

bool ChainManager::setNumberFound(int num)
{
	if ( num <= this->minN || num > this->maxN )
	{
		return false;
	}

	if ( (num % 2) == 0 )
	{
		return false;
	}

	int pos = num - this->minN;
	int odd = (pos - 1) / 2;

	int bit = odd % 6;
	int byte = odd / 6;
	this->found_numbers[byte] = (this->found_numbers[byte]) | (1 << bit);

	return true;
}


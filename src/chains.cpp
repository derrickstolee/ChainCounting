/*
 * chains.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: derrickstolee
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ChainManager.hpp"

int main(int argc, char** argv)
{
	ChainManager* manager = 0;

	int k = 0; /* k = number of crossings */
	int j = 0; /* j = formula number */
	int maxN = 0; /* maximum number to care about */
	int minN = 0; /* minimum number to care about */
	int a = 0; /* maximum value to consider at each position */
	int maxSum = 0; /* maximum sum to consider over all positions */

	for ( int i = 1; i < argc; i++ )
	{
		if ( argv[i][0] == '-' && i < argc - 1 )
		{
			switch ( argv[i][1] )
			{
			case 'K':
				k = atoi(argv[i + 1]);
				break;

			case 'J':
				j = atoi(argv[i + 1]);
				break;

			case 'n':
				minN = atoi(argv[i + 1]);
				break;

			case 'N':
				maxN = atoi(argv[i + 1]);
				break;

			case 'a':
				a = atoi(argv[i + 1]);
				break;

			case 'S':
				maxSum = atoi(argv[i + 1]);
				break;

			default:
				break;
			}
		}
	}

	manager = new ChainManager(k, j, minN, maxN, a, maxSum);

	manager->importArguments(argc, argv);

	while ( manager->readJob(stdin) >= 0 )
	{
		manager->doSearch();
	}

	delete manager;

	return 0;
}


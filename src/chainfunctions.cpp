/*
 * chainfunctions.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: derrickstolee
 */

#include <math.h>
#include "chainfunctions.hpp"

/****************************************************************************************/
/****************************************************************************************/

int chainK2N000(int* a)
{
	int num = 0;
	num += 1;

	/* path: [0, 1, 2, 3] */
	num += (1 << (a[0] + a[1] + a[2])) - 1;

	/* path: [0, 1, 6, 7] */
	num += ((1 << (a[0] + 1)) - 1) * ((1 << a[5]) - 1);

	/* path: [4, 5, 2, 3] */
	num += ((1 << (a[3] + 1)) - 1) * ((1 << a[2]) - 1);

	/*  path: [4, 5, 6, 7] */
	num += ((1 << (a[3] + a[4] + a[5])) - 1);

	return num;
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/

int chainK3N000(int* a)
{
	int num = 0;
	num += 1;

	/* path: [0, 1, 2, 8, 9] */
	num += ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << a[7]) - 1);

	/* path: [0, 1, 2, 3, 4] */
	num += ((1 << (a[0] + a[1] + a[2] + a[3])) - 1);

	/*  path: [0, 1, 7, 8, 9] */
	num += ((1 << (a[0] + 1)) - 1) * ((1 << a[6]) - 1) * (1 << a[7]);

	/* path: [5, 6, 3, 4] */
	num += ((1 << (a[4] + 1)) - 1) * ((1 << a[3]) - 1);

	/*  path: [5, 6, 7, 8, 9] */
	num += ((2 << (a[4] + a[5] + a[6] + a[7])) - 1);

	return num;
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/

int chainK4N000(int* a)
{
	int num = 0;
	num += 1;

	/* path: [0, 1, 8, 9, 10, 11] */
	num += ((1 << (a[0] + 1)) - 1) * ((1 << a[7]) - 1) * (1 << (a[8] + a[9]));

	// path: [0, 1, 2, 9, 10, 11]
	num += ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << a[8]) - 1) * (1 << a[9]);

	// path: [0, 1, 2, 3, 10, 11]
	num += ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << a[9]) - 1);

	// path: [0, 1, 2, 3, 4, 5]
	num += ((1 << (a[0] + a[1] + a[2] + a[3] + a[4])) - 1);

	// path: [6, 7, 8, 9, 10, 11]
	num += ((1 << (a[5] + a[6] + a[7] + a[8] + a[9])) - 1);

	// path: [6, 7, 4, 5]
	num += ((1 << (a[5] + 1)) - 1) * ((1 << a[4]) - 1);

	return num;
}

int chainK4N001(int* a)
{
	int num = 0;
	num += 1;

	// path: [0, 1, 9, 10, 11]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << a[8]) - 1) * (1 << a[9]);

	// path: [0, 1, 2, 10, 11]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << a[9]) - 1);

	// path: [0, 1, 2, 3, 4, 5]
	num += ((1 << (a[0] + a[1] + a[2] + a[3] + a[4])) - 1);

	// path: [6, 7, 8, 9, 10, 11]
	num += ((1 << (a[5] + a[6] + a[7] + a[8] + a[9])) - 1);

	// path: [6, 7, 8, 4, 5]
	num += ((1 << (a[5] + a[6] + 1)) - 1) * ((1 << a[4]) - 1);

	// path: [6, 7, 3, 4, 5]
	num += ((1 << (a[5] + 1)) - 1) * ((1 << a[3]) - 1) * (1 << a[4]);

	return num;

}

int chainK4N002(int* a)
{
	int num = 0;
	num += 1;

	// path: [0, 1, 8, 9, 10, 11]
	num += ((1 << (a[0] + 1)) - 1) * ((1 << (a[7] + a[8])) - 1) * (1 << a[9]);

	// path: [0, 1, 8, 9, 4, 5]
	num += ((1 << (a[0] + 1)) - 1) * ((1 << (a[7] + 1)) - 1) * ((1 << a[4]) - 1);

	// path: [0, 1, 2, 3, 10, 11]
	num += ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << a[9]) - 1);

	// path: [0, 1, 2, 3, 4, 5]
	num += ((1 << (a[0] + a[1] + a[2] + a[3] + a[4])) - 1);

	// path: [6, 7, 8, 9, 10, 11]
	num += ((1 << (a[5] + a[6] + a[7] + a[8] + a[9])) - 1);

	// path: [6, 7, 8, 9, 4, 5]
	num += ((1 << (a[5] + a[6] + a[7] + 1)) - 1) * ((1 << a[4]) - 1);

	// path: [6, 7, 2, 3, 10, 11]
	num += ((1 << (a[5] + 1)) - 1) * ((1 << (a[2] + 1)) - 1) * ((1 << a[9]) - 1);

	// path: [6, 7, 2, 3, 4, 5]
	num += ((1 << (a[5] + 1)) - 1) * ((1 << (a[2] + a[3])) - 1) * (1 << a[4]);

	return num;

}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/

int chainK5N000(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 8, 9, 10, 11, 13]
	num += ((1 << (a[0] + 1)) - 1) * ((1 << a[8]) - 1) * (1 << (a[9] + a[10] + a[11]));
	// path: [0, 1, 2, 9, 10, 11, 13]
	num += ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[9])) - 1) * (1 << (a[10] + a[11]));
	// path: [0, 1, 2, 3, 10, 11, 13]
	num += ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << a[10]) - 1) * (1 << a[11]);
	// path: [0, 1, 2, 3, 4, 11, 13]
	num += ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << a[11]) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6]
	num += ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5])) - 1);
	// path: [6, 7, 8, 9, 10, 11, 13]
	num += ((1 << (a[6] + a[7] + a[8] + a[9] + a[10] + a[11])) - 1);
	// path: [6, 7, 5, 6]
	num += ((1 << (a[6] + 1)) - 1) * ((1 << a[5]) - 1);

	return num;
}

int chainK5N001(int* a)
{
	int num = 0;
	num += 1;

	// path: [0, 1, 2, 10, 11, 13]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11]));
	// path: [0, 1, 2, 3, 11, 13]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[11])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5])) - 1);
	// path: [0, 1, 9, 10, 11, 13]
	num += 1 * ((1 << (a[0] + 1)) - 1) * (((1 << (a[9])) - 1)) * (1 << (a[10] + a[11]));
	// path: [6, 7, 8, 9, 10, 11, 13]
	num += 1 * ((1 << (a[6] + a[7] + a[8] + a[9] + a[10] + a[11])) - 1);
	// path: [6, 7, 8, 5, 6]
	num += 1 * ((1 << (a[6] + a[7] + 1)) - 1) * ((1 << (a[5])) - 1);
	// path: [6, 7, 4, 5, 6]
	num += 1 * ((1 << (a[6] + 1)) - 1) * ((1 << (a[4])) - 1) * (1 << (a[5]));
	return num;
}

int chainK5N002(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 8, 9, 10, 11, 13]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[8])) - 1) * (1 << (a[9] + a[10] + a[11]));
	// path: [0, 1, 8, 9, 10, 5, 6]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[8])) - 1) * (1 << (a[9] + 1)) * ((1 << (a[5])) - 1);
	// path: [0, 1, 2, 9, 10, 11, 13]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[9] + a[10])) - 1) * (1 << (a[11]));
	// path: [0, 1, 2, 9, 10, 5, 6]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[9] + 1)) - 1) * ((1 << (a[5])) - 1);
	// path: [0, 1, 2, 3, 4, 11, 13]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[11])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5])) - 1);
	// path: [6, 7, 8, 9, 10, 11, 13]
	num += 1 * ((1 << (a[6] + a[7] + a[8] + a[9] + a[10] + a[11])) - 1);
	// path: [6, 7, 8, 9, 10, 5, 6]
	num += 1 * ((1 << (a[6] + a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[5])) - 1);
	// path: [6, 7, 3, 4, 11, 13]
	num += 1 * ((1 << (a[6] + 1)) - 1) * ((1 << (a[3])) - 1) * ((1 << (a[11])) - 1);
	// path: [6, 7, 3, 4, 5, 6]
	num += 1 * ((1 << (a[6] + 1)) - 1) * ((1 << (a[3] + a[4])) - 1) * (1 << (a[5]));
	return num;
}

int chainK5N003(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 8, 9, 10, 11, 13]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[8] + a[9])) - 1) * (1 << (a[10] + a[11]));
	// path: [0, 1, 8, 9, 5, 6]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[8])) - 1) * ((1 << (a[5])) - 1);
	// path: [0, 1, 2, 10, 11, 13]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11]));
	// path: [0, 1, 2, 3, 4, 11, 13]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[11])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5])) - 1);
	// path: [6, 7, 8, 9, 10, 11, 13]
	num += 1 * ((1 << (a[6] + a[7] + a[8] + a[9] + a[10] + a[11])) - 1);
	// path: [6, 7, 8, 9, 5, 6]
	num += 1 * ((1 << (a[6] + a[7] + a[8] + 1)) - 1) * ((1 << (a[5])) - 1);
	// path: [6, 7, 3, 4, 11, 13]
	num += 1 * ((1 << (a[6] + 1)) - 1) * ((1 << (a[3])) - 1) * ((1 << (a[11])) - 1);
	// path: [6, 7, 3, 4, 5, 6]
	num += 1 * ((1 << (a[6] + 1)) - 1) * ((1 << (a[3] + a[4])) - 1) * (1 << (a[5]));
	return num;
}

int chainK5N004(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 8, 9, 10, 11, 13]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[8] + a[9])) - 1) * (1 << (a[10] + a[11]));
	// path: [0, 1, 8, 9, 5, 6]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[8] + 1)) - 1) * ((1 << (a[5])) - 1);
	// path: [0, 1, 2, 3, 10, 11, 13]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11]));
	// path: [0, 1, 2, 3, 4, 11, 13]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[11])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5])) - 1);
	// path: [6, 7, 8, 9, 10, 11, 13]
	num += 1 * ((1 << (a[6] + a[7] + a[8] + a[9] + a[10] + a[11])) - 1);
	// path: [6, 7, 8, 9, 5, 6]
	num += 1 * ((1 << (a[6] + a[7] + a[8] + 1)) - 1) * ((1 << (a[5])) - 1);
	// path: [6, 7, 2, 3, 10, 11, 13]
	num += 1 * ((1 << (a[6] + 1)) - 1) * ((1 << (a[2] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11]));
	// path: [6, 7, 2, 3, 4, 11, 13]
	num += 1 * ((1 << (a[6] + 1)) - 1) * ((1 << (a[2] + a[3] + 1)) - 1) * ((1 << (a[11])) - 1);
	// path: [6, 7, 2, 3, 4, 5, 6]
	num += 1 * ((1 << (a[6] + 1)) - 1) * ((1 << (a[2] + a[3] + a[4])) - 1) * (1 << (a[5]));
	return num;
}

/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/

int chainK6N000(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11] + a[12] + a[13]));
	// path: [0, 1, 2, 3, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 2, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * (1 << (a[10] + a[11] + a[12] + a[13]));
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[6])) - 1);
	return num;
}

int chainK6N001(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 2, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11] + a[12] + a[13]));
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	return num;
}

int chainK6N002(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11] + a[12] + a[13]));
	// path: [0, 1, 2, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11] + 1)) * ((1 << (a[6])) - 1);
	// path: [0, 1, 2, 3, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[11] + a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 2, 3, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[11] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * (1 << (a[10] + a[11] + a[12] + a[13]));
	// path: [0, 1, 9, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * (1 << (a[10] + a[11] + 1)) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 4, 5, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [7, 8, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[4] + a[5])) - 1) * (1 << (a[6]));
	return num;
}

int chainK6N003(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10] + a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 2, 10, 11, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10])) - 1) * ((1 << (a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * (1 << (a[10] + a[11] + a[12] + a[13]));
	// path: [0, 1, 9, 10, 11, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * (1 << (a[10] + 1)) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 11, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 4, 5, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [7, 8, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[4] + a[5])) - 1) * (1 << (a[6]));
	return num;
}

int chainK6N004(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 2, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + a[10])) - 1) * (1 << (a[11] + a[12] + a[13]));
	// path: [0, 1, 9, 10, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 4, 5, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [7, 8, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[4] + a[5])) - 1) * (1 << (a[6]));
	return num;
}

int chainK6N005(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 5, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + 1)) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[4])) - 1) * (1 << (a[5] + a[6]));

	return num;
}

int chainK6N006(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 8, 9, 10, 3, 4, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[8])) - 1) * (1 << (a[9] + 1)) * ((1 << (a[3] + 1)) - 1) * ((1
			<< (a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 8, 9, 10, 3, 4, 5, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[8])) - 1) * (1 << (a[9] + 1)) * ((1 << (a[3] + a[4] + 1)) - 1) * ((1
			<< (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 8, 9, 10, 3, 4, 5, 6, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[8])) - 1) * (1 << (a[9] + 1))
			* ((1 << (a[3] + a[4] + a[5] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 8, 9, 10, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[8])) - 1) * (1 << (a[9] + 1)) * ((1 << (a[3] + a[4] + a[5] + a[6]))
			- 1);
	// path: [0, 1, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[8])) - 1) * (1 << (a[9] + a[10] + a[11] + a[12] + a[13]));
	// path: [0, 1, 2, 9, 10, 3, 4, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[9] + 1)) - 1) * ((1 << (a[3] + 1)) - 1)
			* ((1 << (a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 2, 9, 10, 3, 4, 5, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[9] + 1)) - 1) * ((1 << (a[3] + a[4] + 1)) - 1) * ((1
			<< (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 2, 9, 10, 3, 4, 5, 6, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[9] + 1)) - 1) * ((1 << (a[3] + a[4] + a[5] + 1)) - 1) * ((1
			<< (a[13])) - 1);
	// path: [0, 1, 2, 9, 10, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[9] + 1)) - 1) * ((1 << (a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[9] + a[10])) - 1) * (1 << (a[11] + a[12] + a[13]));
	// path: [0, 1, 2, 3, 4, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 2, 3, 4, 5, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 2, 3, 4, 5, 6, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [7, 8, 9, 10, 3, 4, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[3] + 1)) - 1) * ((1 << (a[11])) - 1) * (1 << (a[12]
			+ a[13]));
	// path: [7, 8, 9, 10, 3, 4, 5, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[3] + a[4] + 1)) - 1) * ((1 << (a[12])) - 1) * (1
			<< (a[13]));
	// path: [7, 8, 9, 10, 3, 4, 5, 6, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[3] + a[4] + a[5] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [7, 8, 9, 10, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);

	return num;
}

int chainK6N007(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10] + a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 2, 10, 11, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * (1 << (a[10] + a[11] + a[12] + a[13]));
	// path: [0, 1, 9, 10, 11, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * (1 << (a[10] + 1)) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 11, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [7, 8, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3] + a[4] + a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 3, 4, 12, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3])) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	return num;
}

int chainK6N008(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 2, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + a[10])) - 1) * (1 << (a[11] + a[12] + a[13]));
	// path: [0, 1, 9, 10, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [7, 8, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3] + a[4] + a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 3, 4, 12, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3])) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	return num;
}

int chainK6N009(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 10, 11, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10] + 1)) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	// path: [0, 1, 2, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10] + a[11] + a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 2, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[10] + a[11])) - 1) * ((1 << (a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 9, 10, 11, 5, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * (1 << (a[10] + 1)) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * (1 << (a[10] + a[11] + a[12] + a[13]));
	// path: [0, 1, 9, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * (1 << (a[10] + a[11] + 1)) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 11, 5, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + 1)) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3] + a[4])) - 1) * (1 << (a[5] + a[6]));
	// path: [7, 8, 3, 4, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3])) - 1) * ((1 << (a[13])) - 1);
	return num;
}

int chainK6N010(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[11] + a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 2, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[11] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + a[10])) - 1) * (1 << (a[11] + a[12] + a[13]));
	// path: [0, 1, 9, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + a[10])) - 1) * (1 << (a[11] + 1)) * ((1 << (a[6])) - 1);
	// path: [0, 1, 9, 10, 5, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 5, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3] + a[4])) - 1) * (1 << (a[5] + a[6]));
	// path: [7, 8, 3, 4, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3])) - 1) * ((1 << (a[13])) - 1);
	return num;
}

int chainK6N011(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + a[10] + a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 9, 10, 11, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + a[10] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [0, 1, 9, 10, 5, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9])) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 11, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 5, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3] + a[4])) - 1) * (1 << (a[5] + a[6]));
	// path: [7, 8, 3, 4, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3])) - 1) * ((1 << (a[13])) - 1);
	return num;
}

int chainK6N012(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[11] + a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 2, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[11] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [0, 1, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11] + a[12] + a[13]));
	// path: [0, 1, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11] + 1)) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 5, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + 1)) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3] + a[4])) - 1) * (1 << (a[5] + a[6]));
	// path: [7, 8, 3, 4, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3])) - 1) * ((1 << (a[13])) - 1);
	return num;
}

int chainK6N013(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[10] + a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 10, 11, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[10])) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 11, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 5, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + 1)) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3] + a[4])) - 1) * (1 << (a[5] + a[6]));
	// path: [7, 8, 3, 4, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3])) - 1) * ((1 << (a[13])) - 1);

	return num;
}

int chainK6N014(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[11] + a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 2, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + 1)) - 1) * ((1 << (a[11])) - 1) * ((1 << (a[6])) - 1);
	// path: [0, 1, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11] + a[12] + a[13]));
	// path: [0, 1, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[10])) - 1) * (1 << (a[11] + 1)) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 4, 5, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + 1)) - 1) * ((1 << (a[4])) - 1) * ((1 << (a[13])) - 1);
	// path: [7, 8, 9, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + 1)) - 1) * ((1 << (a[4] + a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3])) - 1) * (1 << (a[4] + 1)) * ((1 << (a[13])) - 1);
	// path: [7, 8, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[3])) - 1) * (1 << (a[4] + a[5] + a[6]));
	return num;
}

int chainK6N015(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 2, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + a[10])) - 1) * (1 << (a[11] + a[12] + a[13]));
	// path: [0, 1, 9, 10, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 2, 3, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[2] + 1)) - 1) * ((1 << (a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [7, 8, 2, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[2] + a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [7, 8, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[2] + a[3] + a[4] + a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 2, 3, 4, 12, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[2] + a[3] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[6])) - 1);
	return num;
}

int chainK6N016(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + a[10] + a[11])) - 1) * (1 << (a[12] + a[13]));
	// path: [0, 1, 9, 10, 11, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + a[10] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [0, 1, 9, 10, 5, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + 1)) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[2] + a[3] + a[4])) - 1) * (1 << (a[5] + a[6]));
	// path: [7, 8, 2, 3, 4, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[2] + a[3] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [7, 8, 2, 3, 12, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[2] + 1)) - 1) * ((1 << (a[12])) - 1) * (1 << (a[13]));
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 11, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 5, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[5])) - 1) * (1 << (a[6]));
	return num;
}

int chainK6N017(int* a)
{
	int num = 0;
	num += 1;
	// path: [0, 1, 2, 3, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[11] + a[12])) - 1) * (1 << (a[13]));
	// path: [0, 1, 2, 3, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + 1)) - 1) * ((1 << (a[11] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6])) - 1);
	// path: [0, 1, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + a[10])) - 1) * (1 << (a[11] + a[12] + a[13]));
	// path: [0, 1, 9, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + a[10])) - 1) * (1 << (a[11] + 1)) * ((1 << (a[6])) - 1);
	// path: [0, 1, 9, 10, 4, 5, 13, 14]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + 1)) - 1) * ((1 << (a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [0, 1, 9, 10, 4, 5, 6, 7]
	num += 1 * ((1 << (a[0] + 1)) - 1) * ((1 << (a[9] + 1)) - 1) * ((1 << (a[4] + a[5])) - 1) * (1 << (a[6]));
	// path: [7, 8, 2, 3, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[2] + 1)) - 1) * ((1 << (a[11] + a[12])) - 1) * (1 << (a[13]));
	// path: [7, 8, 2, 3, 11, 12, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[2] + 1)) - 1) * ((1 << (a[11] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 2, 3, 4, 5, 13, 14]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[2] + a[3])) - 1) * (1 << (a[4] + 1)) * ((1 << (a[13])) - 1);
	// path: [7, 8, 2, 3, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + 1)) - 1) * ((1 << (a[2] + a[3])) - 1) * (1 << (a[4] + a[5] + a[6]));
	// path: [7, 8, 9, 10, 11, 12, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + a[12] + a[13])) - 1);
	// path: [7, 8, 9, 10, 11, 12, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + a[10] + a[11] + 1)) - 1) * ((1 << (a[6])) - 1);
	// path: [7, 8, 9, 10, 4, 5, 13, 14]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[4] + 1)) - 1) * ((1 << (a[13])) - 1);
	// path: [7, 8, 9, 10, 4, 5, 6, 7]
	num += 1 * ((1 << (a[7] + a[8] + a[9] + 1)) - 1) * ((1 << (a[4] + a[5])) - 1) * (1 << (a[6]));
	return num;
}

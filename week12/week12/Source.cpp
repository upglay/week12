#include <iostream>
#include <ostream>

#define MAX2(a, b)					((a) > (b) ? (a) : (b))
#define MAX3(a, b, c)				(MAX2(MAX2(a, b), (c)))
#define MAX4(a, b, c, d)			(MAX2(MAX3(a, b, c), (d)))

class CellData
{
public:
	double q_[4] = { 0.0, 0.0, 0.0, 0.0 }; //up, down, left, right
	double reward_ = 0.0;

	CellData()
	{}

	~CellData()
	{}

	double getMaxQ()
	{
		return MAX4(q_[0], q_[1], q_[2], q_[3]);
	}
};

class GridWorld
{
public:
	int i_res_, j_res_;
	CellData *q_arr2d_ = nullptr;

	GridWorld(const int& i_res, const int& j_res)
		:i_res_(i_res), j_res_(j_res)
	{
		q_arr2d_ = new CellData[i_res*j_res];
	}

	CellData& getCell(const int& i, const int& j)
	{
		return q_arr2d_[i + i_res_ * j];
	}

	bool isInside(const int& i, const int& j)
	{
		if (i < 0) return false;
		if (i >= i_res_)return false;

		if (j < 0)return false;
		if (j >= j_res_)return false;

		return true;
	}

	void printSigned(const float& v)
	{
		if (v > 0.0f) printf("+%1.1f", v);
		else if (v < 0.0f) printf("%1.1f", v);
		else
			printf(" 0.0");
	}
	
	void print()
	{
		for (int j = j_res_ - 1; j >= 0; j--)
		{
			for (int i = 0; i < i_res_; i++)
			{
				CellData &cell = getCell(i, j);

				printf("   "); printSigned(cell.q_[0]); printf("   ");
				printf("   ");
			}

			printf("\n");

			for (int i = 0; i < i_res_; i++)
			{
				CellData &cell = getCell(i, j);
				printSigned(cell.q_[2]); printf("  "); printSigned(cell.q_[3]);
				printf("   ");
			}

			printf("\n");

			for (int i = 0; i < i_res_; i++)
			{
				CellData &cell = getCell(i, j);

				printf("   "); printSigned(cell.q_[1]); printf("   ");
				printf("   ");
			}

			printf("\n\n");
		}
	}
};

std::ostream& operator<<(std::ostream& os, GridWorld& g)
{
	for (int j = g.j_res_ - 1; j >= 0; j--)
	{
		for (int i = 0; i < g.i_res_; i++)
		{
			CellData &cell = g.getCell(i, j);

		}
	}

	return os;
}

class Agent
{
public:
	int i_, j_;
	double reward_;

	Agent()
		:i_(0),j_(0), reward_(0.0)
	{}
};

int main()
{

	const int world_res_i = 3, world_res_j = 2;
	
	GridWorld world(world_res_i, world_res_j);

	//for (int j = 0; j < world_res_j; j++)
	//for (int i = 0; i < world_res_i; i++)
	//{
	//	world.getCell(i, j).reward_ = -0.1;
	//}

	world.getCell(2, 1).reward_ = 1.0;
	world.getCell(2, 0).reward_ = -1.0;

	Agent my_agent;

	world.print();

	//trained
	for (int t = 0; t < 10000; t++)
	{
		const int action = rand() % 4;

		int i = my_agent.i_, j = my_agent.j_;
		int i_old = i, j_old = j;

		switch (action)
		{
		case 0:
			j++;
			break;
		case 1:
			j--;
			break;
		case 2:
			i--;
			break;
		case 3:
			i++;
			break;
		}

		if (world.isInside(i, j) == true)
		{
			//move agent
			
			//update reward (r_t)

			//update q values of previous cell (q_t)

			//reset if agent is in final cells
		}
		else
		{

		}
	}


	world.print();

	return 0;
}
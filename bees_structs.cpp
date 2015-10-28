#include<iostream>
using namespace std;

typedef int Pollen;

const int FSIZE = 9;

struct Patch
{
  Pollen pollen;
  int    bees;
};

struct Field
{
  Patch patch[FSIZE][FSIZE];
};

Field field;


const Pollen PATCH_CAPACITY = 9;

void init(Patch& patch)
{
  patch.pollen = PATCH_CAPACITY;
  patch.bees   = 0;
}

void init(Field& fd)
{
  for (int i = 0; i < FSIZE; i++)
  {
    for (int j = 0; j < FSIZE; j++)
    {
      init(fd.patch[i][j]);
    }
  }
}

void print(const Patch& patch)
{
  cout << patch.pollen;

  switch (patch.bees)
  {
    case 0: cout << ' '; break;
    case 1: cout << '.'; break;
    case 2: cout << ':'; break;

    default: cout << '*'; break;
  }
}

void print(const Field& field)
{
  for (int i = 0; i < FSIZE; i++)
  {
    for (int j = 0; j < FSIZE; j++)
    {
      print(field.patch[i][j]);

      cout << ' ';
    }

    cout << endl;
  }
}
enum BeeState { SEARCHING, GATHERING, RETURNING, DEPOSITING };

struct Bee
{
  BeeState state;
  int      x, y;
  Pollen   pollen;
};

const int NBEES = 10;

Bee bees[NBEES];

void init(Bee& bee, int x, int y)
{
  bee.state = SEARCHING;
  bee.x = x;
  bee.y = y;
  bee.pollen = 0;

  field.patch[bee.x][bee.y].bees++;
}

template<typename T>
T minimum(T x, T y)
{
  return x < y ? x : y;
}

template<typename T>
T maximum(T x, T y)
{
  return x > y ? x : y;
}

void work(Bee& bee)
{
  switch (bee.state)
  {
    case SEARCHING:
    {
      field.patch[bee.x][bee.y].bees--;

      switch (rand() % 4)
      {
        case 0: bee.x = maximum(bee.x - 1, 0); break;
        case 1: bee.y = maximum(bee.y - 1, 0); break;
        case 2: bee.x = minimum(bee.x + 1, FSIZE - 1); break;
        case 3: bee.y = minimum(bee.y + 1, FSIZE - 1); break;
      }

      field.patch[bee.x][bee.y].bees++;

      break;
    }
    case GATHERING:
    {
      cout <<"Gathering" <<endl; break;
    }
    case RETURNING:
    {
      cout <<"Returning" <<endl; break;
    }
    case DEPOSITING:
    {
      cout<< "Depositing" <<endl; break;
    }
    default:
    {
      cout<< "Doing Nothing" <<endl; break;
    }
  }
}
int main()
{
  init(field);

  print(field);

  for (int i = 0; i < NBEES; i++)
  {
    init(bees[i], FSIZE/2, FSIZE/2);
  }

  while (true)
  {
    for (int i = 0; i < NBEES; i++)
    {
      work(bees[i]);
    }
    cin.get();
  }
}

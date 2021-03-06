#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Student
{
  string m_name;
  vector<double> m_scores;
  string m_standing;
  // added for caching
  mutable bool m_cacheStale;
  mutable double m_gpa;

public:
  Student(std::string name) :
    m_name(name), m_standing("good"), m_cacheStale(true), m_gpa(0.0) {}

  void addScore(double score) {
   m_cacheStale = true;
    m_scores.push_back(score);
  }

  std::string name() const { return m_name; }
  void name(std::string name) { m_name = name; }

  double gpa() const {
   if (m_cacheStale) {
      m_cacheStale = false;
      double sum = std::accumulate(m_scores.begin(), m_scores.end(), 0.0);
      m_gpa = sum / m_scores.size();
    }
    return m_gpa;
  }
};

void printStudent(const Student& s) { 
/* your implementation here */
cout<< s.name() << " and his avg gpa is : " << s.gpa() <<   endl;
}
 
int main()
{
  Student s1("Bradley");
 
  s1.addScore(3.5);
  s1.addScore(3.9);
 
  printStudent(s1); // what happens
}

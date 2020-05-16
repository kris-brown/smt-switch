#include <iostream>

#include "cvc4_factory.h"
#include "smt.h"
// after full installation
// #include "smt-switch/cvc4_factory.h"
// #include "smt-switch/smt.h"

using namespace std;
using namespace smt;

int main()
{
  SmtSolver s = CVC4SolverFactory::create(false);
  Term x = s->make_symbol("x", s->make_sort(BV, 8));
  Term y = s->make_symbol("y", s->make_sort(BV, 8));
  cout << x->to_string() << endl;
  cout << y->to_string() << endl;
  Term xpy = s->make_term(BVAdd, x, y);
  cout << xpy->to_string() << endl;
  Term xext = s->make_term(Op(Extract, 3, 0), x);
  cout << xext << endl;
  Term _true = s->make_term(true);
  cout << _true << endl;
  Term _one = s->make_term(1, s->make_sort(INT));
  cout << _one << endl;
  Term _one_r = s->make_term("1.0", s->make_sort(REAL));
  cout << _one_r << endl;
  Term _two_bv = s->make_term(2, s->make_sort(BV, 4));
  cout << _two_bv << endl;
  Term _three_bv = s->make_term("3", s->make_sort(BV, 4));
  cout << _three_bv << endl;

  cout << "Children of " << xpy << endl;
  for (auto c : xpy)
  {
    cout << "\t" << c << endl;
  }


  return 0;
}

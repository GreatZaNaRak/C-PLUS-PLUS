#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
using namespace std;
int eval_postfix(vector<pair<int,int> > v) {
    /// 1 = operand
    /// 0 = +, 1 = -, 2 = *, 3 = /
    vector<int> res;
    for (int i = 0 ; i < v.size() ; i++) {
        if (v[i].first == 1) res.push_back(v[i].second);
        else {
            int op1 = res[res.size()-2], op2 = res[res.size()-1];
            res.pop_back(); res.pop_back();
            switch (v[i].second) {
                case 0 : res.push_back(op1 + op2); break;
                case 1 : res.push_back(op1 - op2); break;
                case 2 : res.push_back(op1 * op2); break;
                case 3 : res.push_back(op1 / op2); break;
            }
        }
    }
    return res[res.size()-1];
}
#endif

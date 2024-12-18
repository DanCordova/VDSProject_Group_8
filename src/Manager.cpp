#include "Manager.h"

namespace ClassProject{
    const BDD_ID &Manager::True() {
        return tru;
    }
    const BDD_ID &Manager::False() {
        return fls;
    }
    BDD_ID Manager::createVar(const std::string &label) {
        if(varID.find(label) != varID.end())
            return varID[label];
        return varID[label] = ++lastID;
    }
    bool Manager::isConstant(BDD_ID f){
        return (f == 0 || f == 1);
    }
    bool Manager::isVariable(BDD_ID f){
        if (f == 0 || f == 1)
            return false;
        for (auto it = varID.begin(); it != varID.end(); it++) {
            if (it->second == f)
                return true;
        }
        return false;
    }
}

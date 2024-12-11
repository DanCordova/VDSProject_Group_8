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
}

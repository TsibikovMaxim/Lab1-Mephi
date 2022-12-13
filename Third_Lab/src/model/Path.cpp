#include "Path.h"

Path::Path(int start) {
    path.push_back(start);
    length = 0;
}

Path& Path::operator=(const Path& p) {
    path = p.getPath();
    length = p.getLength();
    return *this;
}

vector<int> Path::getPath() const { return path; }

int Path::getLength() const { return length; }

void Path::push_back(int v, int l) {
    path.push_back(v);
    length += l;
}

void Path::push_back(Path p) {
    for (size_t i = 0; i < p.getPath().size(); ++i) {
        int last = path[path.size() - 1];
        if (last != p.getPath()[i])
            path.push_back(p.getPath()[i]);
    }
    length += p.getLength();
}

string Path::toString() {
    string res = "";
    size_t n = getPath().size();
    for (size_t i = 0; i < n; i++) {
        res += to_string(getPath()[i] + 1);
        if (i != n - 1)
            res += "->";
        else
            res += " (";
    }
    res += to_string(getLength()) + ')';
    return res;
}

ostream& operator<<(ostream& os, const Path& p) {
    size_t n = p.getPath().size();
    for (size_t i = 0; i < n; i++) {
        os << p.getPath()[i] + 1;
        if (i != n - 1)
            os << "->";
         else
            os << " (";
    }
    os << p.getLength() << ')' << endl;
    return os;
}

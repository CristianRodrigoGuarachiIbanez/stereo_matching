//
// Created by cristian on 12.10.21.
//

int HammingDistance(const int& a, const int& b) {
    int d = a ^ b;
    int res = 0;
    while (d > 0) {
        res += d & 1;
        d >>= 1;
    }
    return res;
}
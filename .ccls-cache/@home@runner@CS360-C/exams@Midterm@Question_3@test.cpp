#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>


template <typename T>
class Polynomial {
private:
    std::vector<T> data;

    void normalize(std::vector<T> &coef) {
        for (auto iter = coef.rbegin(); iter != coef.rend(); ++iter) {
            if (*iter == T(0)) {
                coef.pop_back();
            } else {
                break;
            }
        }
    }

public:
    Polynomial<T>(const std::vector<T> &a):data(a) {
        normalize(data);
    }

    template <typename Iter>
    Polynomial<T>(Iter first, Iter last) :data(first, last) {
        normalize(data);
    }

    Polynomial<T>(const T &num = T()) {
        data.push_back(num);
        normalize(data);
    }

    T operator [] (size_t i) const {
        if (i >= data.size()) {
            return T(0);
        } else {
            return data[i];
        }
    }

    long long Degree() const {
        if (data.empty()) {
            return -1;
        } else {
            return static_cast<int>(data.size()) - 1;
        }
    }

    bool operator == (const Polynomial<T> &other) const {
        if (data.size() != other.data.size()) {
            return false;
        }
        for (size_t i = 0; i != data.size(); ++i) {
            if (data[i] != other[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator != (const Polynomial<T> &other) const {
        return !(*this == other);
    }

    bool operator ==(const T &num) {
        return *this == Polynomial<T>(num);
    }

    bool operator !=(const T &num) {
        return *this != Polynomial<T>(num);
    }

    Polynomial<T>& operator += (const Polynomial<T> &other) {
        data.resize(std::max(other.data.size(), data.size()), T(0));
        for (size_t i = 0; i != std::min(data.size(), other.data.size()); ++i) {
            data[i] += other.data[i];
        }
        normalize(data);
        return *this;
    }

    Polynomial<T>& operator -= (const Polynomial<T> &other) {
        data.resize(std::max(other.data.size(), data.size()), T(0));
        for (size_t i = 0; i != std::min(data.size(), other.data.size()); ++i) {
            data[i] -= other.data[i];
        }
        normalize(data);
        return *this;
    }

    Polynomial<T>& operator +=(const T &num) {
        *this += Polynomial<T>(num);
        normalize(data);
        return *this;
    }

    Polynomial<T>& operator -=(const T &num) {
        *this -= Polynomial<T>(num);
        normalize(data);
        return *this;
    }

    Polynomial<T>& operator *=(const Polynomial<T> &other) {
        std::vector<T> temp(data.size() + other.data.size(), T(0));
        for (size_t i = 0; i != data.size(); ++i) {
            for (size_t j = 0; j != other.data.size(); ++j) {
                temp[i + j] += data[i] * other.data[j];
            }
        }
        normalize(temp);
        *this = Polynomial(temp);
        return *this;
    }

    Polynomial<T>& operator *=(const T &num) {
        for (size_t i = 0; i != data.size(); ++i) {
            data[i] *= num;
        }
        normalize(data);
        return *this;
    }

    T operator () (const T &point) const {
        T ans = T(0);
        for (auto iter = data.rbegin(); iter != data.rend(); ++iter) {
            ans += *iter;
            if ((iter + 1) != data.rend()) {
                ans *= point;
            }
        }
        return ans;
    }

    friend std::ostream& operator << (std::ostream& out, const Polynomial<T> &pol) {
        bool flag = false;
        unsigned long long degree = pol.data.size() - 1;
        for (auto iter = pol.data.rbegin(); iter != pol.data.rend(); ++iter, --degree) {
            T coef = *iter;
            if (coef != T(0)) {
                if (coef > T(0) && flag) {
                    out << '+';
                }
                flag = true;
                if (degree == 0) {
                    out << coef;
                } else if (coef == T(1)) {
                    out << 'x';
                } else if (coef == T(-1)) {
                    out << "-x";
                } else {
                    out << coef << "*x";
                }
                if (degree > 1) {
                    out << '^' << degree;
                }
            }
        }
        if (pol.data.size() == 0) {
            out << 0;
        }
        return out;
    }

    friend Polynomial<T> operator&(const Polynomial<T> &first, const Polynomial<T> &second) {
        Polynomial<T> comp(first.data.at(0));
        Polynomial<T> copy(second.data);
        size_t iter = 1;
        for (size_t degree = 1; degree != first.data.size(); ++degree) {
            for (; iter != degree; ++iter) {
                copy *= second;
            }
            comp += copy * first.data[degree];
        }
        return comp;
    }

    Polynomial<T> &operator /= (const Polynomial<T> &other) {
        Polynomial<T> priv(T(0));
        while (data.size() >= other.data.size()) {
            T coef = data.back() / other.data.back();
            size_t degree = data.size() - other.data.size();
            std::vector<T> div(degree + 1);
            div.back() = coef;
            Polynomial<T> temp(div);
            *this -= other * temp;
            priv += temp;
        }
        data = priv.data;
        return *this;
    }

    Polynomial<T> &operator %= (const Polynomial<T> &other) {
        Polynomial<T> quotient = *this / other;
        *this -= other * quotient;
        return *this;
    }

    friend Polynomial<T> operator,(const Polynomial<T> &first, const Polynomial<T> &second) {
        Polynomial<T> gcd = first;
        Polynomial<T> copy = second;
        while (copy.data.size() != 0) {
            gcd %= copy;
            std::swap(gcd, copy);
        }
        if (gcd.data.size() != 0) {
            Polynomial<T> temp(gcd[gcd.data.size() - 1]);
            gcd /= temp;
        }
        return gcd;
    }

    auto begin() const {
        return data.begin();
    }

    auto end() const {
        return data.end();
    }
};

template <typename T>
Polynomial<T> operator *(Polynomial<T> first, const Polynomial<T> &second) {
    return first *= second;
}

template <typename T>
Polynomial<T> operator +(Polynomial<T> first, const Polynomial<T> &second) {
    return first += second;
}

template <typename T>
Polynomial<T> operator -(Polynomial<T> first, const Polynomial<T> &second) {
    return first -= second;
}

template<typename T>
Polynomial<T> operator /(const Polynomial<T> &first, const Polynomial<T> &second) {
    auto copy = first;
    copy /= second;
    return copy;
}

template<typename T>
Polynomial<T> operator %(const Polynomial<T> &first, const Polynomial<T> &second) {
    auto copy = first;
    copy %= second;
    return copy;
}

template <typename T>
Polynomial<T> operator +(Polynomial<T> poly, const T &num) {
    return poly += Polynomial<T>(num);
}

template <typename T>
Polynomial<T> operator +(const T &num, Polynomial<T> poly) {
    return poly += Polynomial<T>(num);
}

template <typename T>
Polynomial<T> operator -(Polynomial<T> poly, const T &num) {
    return poly -= Polynomial<T>(num);
}

template <typename T>
Polynomial<T> operator -(const T &num, Polynomial<T> poly) {
    return Polynomial<T>(num) -= poly;
}

template <typename T>
Polynomial<T> operator *(Polynomial<T> poly, const T &num) {
    return  poly *= Polynomial<T>(num);
}

template <typename T>
Polynomial<T> operator *(const T &num, Polynomial<T> poly) {
    return  poly *= Polynomial<T>(num);
}
// @Author by : hyxinchou
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional < std::is_same<T, __int128_t>::value ||
    std::is_same<T, __int128>::value,
    std::true_type,
    std::false_type >::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional < std::is_same<T, __uint128_t>::value ||
    std::is_same<T, unsigned __int128>::value,
    std::true_type,
    std::false_type >::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
    __uint128_t,
    unsigned __int128>;

template <class T>
using is_integral = typename std::conditional < std::is_integral<T>::value ||
                    is_signed_int128<T>::value ||
                    is_unsigned_int128<T>::value,
                    std::true_type,
                    std::false_type >::type;

template <class T>
using is_signed_int = typename std::conditional < (is_integral<T>::value &&
                      std::is_signed<T>::value) ||
                      is_signed_int128<T>::value,
                      std::true_type,
                      std::false_type >::type;

template <class T>
using is_unsigned_int =
    typename std::conditional < (is_integral<T>::value &&
                                 std::is_unsigned<T>::value) ||
    is_unsigned_int128<T>::value,
    std::true_type,
    std::false_type >::type;

template <class T>
using to_unsigned = typename std::conditional <
                    is_signed_int128<T>::value,
                    make_unsigned_int128<T>,
                    typename std::conditional<std::is_signed<T>::value,
                    std::make_unsigned<T>,
                    std::common_type<T>>::type >::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional < is_integral<T>::value && std::is_signed<T>::value,
    std::true_type,
    std::false_type >::type;

template <class T>
using is_unsigned_int =
    typename std::conditional < is_integral<T>::value &&
    std::is_unsigned<T>::value,
    std::true_type,
    std::false_type >::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
      std::make_unsigned<T>,
      std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

const int64_t INF64 = 2E18;
const int INF = 2E9 + 5;

template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n, std::make_pair(INF64, INF64)) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] = std::min(U(x), data[p - 1]);
            p += p & -p;
        }
    }

    T Min(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return std::min(Min(l), Min(r));
    }

private:
    int _n;
    std::vector<U> data;

    U Min(int r) {
        U s = std::make_pair(INF64, INF64);
        while (r > 0) {
            s = std::min(U(s), data[r - 1]);
            r -= r & -r;
        }
        return s;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    // Insert your code
    int N; std::cin >> N;
    std::vector<std::array<int64_t, 3>> Points(N);
    std::vector<int> zip;
    for (int i = 0; i < N; ++i) {
        std::cin >> Points[i][0] >> Points[i][1];
        Points[i][2] = i;
        zip.push_back(Points[i][1]);
    }
    std::sort(all(Points));
    std::sort(all(zip));
    zip.erase(std::unique(all(zip)), zip.end());
    std::array<int64_t, 3> answer = {INF64, INF64, INF64};
    fenwick_tree<std::pair<int64_t, int64_t>> fw(N + 10);
    // std::abs(Ai - Aj) + std::abs(Bi - Bj)(*), but Ai >= Aj && Bi >= Bj => (*) = Ai + Bi - (Aj + Bj) && Ai + Bi >= Aj + Bj
    for (int i = 0; i < N; ++i) {
        int l = std::lower_bound(all(zip), Points[i][1]) - zip.begin();
        auto v = fw.Min(l, l);
        if (v.first < INF) {
            answer = std::min(answer, {Points[i][0] + Points[i][1] + v.first, v.second, Points[i][2]});
        }
        fw.add(l, std::make_pair(-(Points[i][0] + Points[i][1]), Points[i][2]));
    }
    if (answer[0] != INF64) {
        std::cout << answer[0] << "\n" << answer[1] + 1 << " " << answer[2] + 1 << "\n";
    } else {
        std::cout << "-1\n";
    }
    return 0;
}
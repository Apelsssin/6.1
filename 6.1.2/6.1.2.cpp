#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <random>
#include <future>
#include <string>
#include <exception>

void clear_vectors(std::vector<int>& vector12, std::vector<int>& vector34, std::vector<int>& vector56, std::vector<int>& vector78) {
    vector12.clear();
    vector34.clear();
    vector56.clear();
    vector78.clear();
}
template<typename T>
bool is_ready(std::future<T>& t) {
    return t.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
};
void summ(std::vector<int> vec1, std::vector<int> vec2, std::vector<int>& res, std::chrono::duration<double>& elapsed_seconds, 
    size_t id_first, size_t id_last) {
    auto start = std::chrono::steady_clock::now();
    if (vec1.size() == vec2.size())
        for (size_t i = id_first; i < id_last; ++i) {
            res.push_back(vec1[i] + vec2[i]);
        }
    else throw std::exception("Different size of vectors.");
    auto end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start;
}
void two_threads(std::vector<int> vec1, std::vector<int> vec2, std::vector<int>& res, std::chrono::duration<double>& req_time) {
    std::thread t1(summ, vec1, vec2, std::ref(res), std::ref(req_time), 0, vec1.size() / 2);
    std::thread t2(summ, vec1, vec2, std::ref(res), std::ref(req_time), vec1.size() / 2, vec1.size());
    t1.join();
    t2.join();
}
void four_threads(std::vector<int> vec1, std::vector<int> vec2, std::vector<int>& res, std::chrono::duration<double>& req_time) {
    std::thread t1(summ, vec1, vec2, std::ref(res), std::ref(req_time), 0, vec1.size() / 4);
    std::thread t2(summ, vec1, vec2, std::ref(res), std::ref(req_time), vec1.size() / 4, vec1.size() / 2);
    std::thread t3(summ, vec1, vec2, std::ref(res), std::ref(req_time), vec1.size() / 2, 3 * vec1.size() / 4);
    std::thread t4(summ, vec1, vec2, std::ref(res), std::ref(req_time), 3 * vec1.size() / 4, vec1.size());
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
void eight_threads(std::vector<int> vec1, std::vector<int> vec2, std::vector<int>& res, std::chrono::duration<double>& req_time) {
    std::thread t1(summ, vec1, vec2, std::ref(res), std::ref(req_time), 0, vec1.size() / 8);
    std::thread t2(summ, vec1, vec2, std::ref(res), std::ref(req_time), vec1.size() / 8, vec1.size() / 4);
    std::thread t3(summ, vec1, vec2, std::ref(res), std::ref(req_time), vec1.size() / 4, 3 * vec1.size() / 8);
    std::thread t4(summ, vec1, vec2, std::ref(res), std::ref(req_time), 3 * vec1.size() / 8, vec1.size() / 2);
    std::thread t5(summ, vec1, vec2, std::ref(res), std::ref(req_time), vec1.size() / 2, 5 * vec1.size() / 8);
    std::thread t6(summ, vec1, vec2, std::ref(res), std::ref(req_time), 5 * vec1.size() / 8, 3 * vec1.size() / 4);
    std::thread t7(summ, vec1, vec2, std::ref(res), std::ref(req_time), 3 * vec1.size() / 4, 7 * vec1.size() / 8);
    std::thread t8(summ, vec1, vec2, std::ref(res), std::ref(req_time), 7 * vec1.size() / 8, vec1.size());
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
}
void sixteen_threads(std::vector<int> vec1, std::vector<int> vec2, std::vector<int>& res, std::chrono::duration<double>& req_time) {
    std::thread t1(summ, vec1, vec2, std::ref(res), std::ref(req_time), 0, vec1.size() / 16);
    std::thread t2(summ, vec1, vec2, std::ref(res), std::ref(req_time), vec1.size() / 16, vec1.size() / 8);
    std::thread t3(summ, vec1, vec2, std::ref(res), std::ref(req_time), vec1.size() / 8, 3 * vec1.size() / 16);
    std::thread t4(summ, vec1, vec2, std::ref(res), std::ref(req_time), 3 * vec1.size() / 16, vec1.size() / 4);
    std::thread t5(summ, vec1, vec2, std::ref(res), std::ref(req_time), vec1.size() / 4, 5 * vec1.size() / 16);
    std::thread t6(summ, vec1, vec2, std::ref(res), std::ref(req_time), 5 * vec1.size() / 16, 3 * vec1.size() / 8);
    std::thread t7(summ, vec1, vec2, std::ref(res), std::ref(req_time), 3 * vec1.size() / 8, 7 * vec1.size() / 16);
    std::thread t8(summ, vec1, vec2, std::ref(res), std::ref(req_time), 7 * vec1.size() / 16, vec1.size() / 2);
    std::thread t9(summ, vec1, vec2, std::ref(res), std::ref(req_time), vec1.size() / 2, 9 * vec1.size() / 16);
    std::thread t10(summ, vec1, vec2, std::ref(res), std::ref(req_time), 9 * vec1.size() / 16, 5 * vec1.size() / 8);
    std::thread t11(summ, vec1, vec2, std::ref(res), std::ref(req_time), 5 * vec1.size() / 8, 11 * vec1.size() / 16);
    std::thread t12(summ, vec1, vec2, std::ref(res), std::ref(req_time), 11 * vec1.size() / 16, 3 * vec1.size() / 4);
    std::thread t13(summ, vec1, vec2, std::ref(res), std::ref(req_time), 3 * vec1.size() / 4, 13 * vec1.size() / 16);
    std::thread t14(summ, vec1, vec2, std::ref(res), std::ref(req_time), 13 * vec1.size() / 16, 7 * vec1.size() / 8);
    std::thread t15(summ, vec1, vec2, std::ref(res), std::ref(req_time), 7 * vec1.size() / 8, 15 * vec1.size() / 16);
    std::thread t16(summ, vec1, vec2, std::ref(res), std::ref(req_time), 15 * vec1.size() / 16, vec1.size());
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    t12.join();
    t13.join();
    t14.join();
    t15.join();
    t16.join();
}
void calculate_and_print(
    std::vector<int> vector1, std::vector<int> vector2, std::vector<int> vector3, std::vector<int> vector4,
    std::vector<int> vector5, std::vector<int> vector6, std::vector<int> vector7, std::vector<int> vector8,
    std::vector<int>& vector12, std::vector<int>& vector34, std::vector<int>& vector56, std::vector<int>& vector78,
    std::chrono::duration<double>& req_time1, std::chrono::duration<double>& req_time2,
    std::chrono::duration<double>& req_time3, std::chrono::duration<double>& req_time4,
     std::string function) {
    if (function == "two_threads") {
        std::future<void> f1 = std::async(std::launch::async, two_threads, vector1, vector2, std::ref(vector12), std::ref(req_time1));
        while (!is_ready(f1)) { ; }
        std::cout << req_time1.count() << "\t";
        std::future<void> f2 = std::async(std::launch::async, two_threads, vector3, vector4, std::ref(vector34), std::ref(req_time2));
        while (!is_ready(f2)) { ; }
        std::cout << req_time2.count() << "\t";
        std::future<void> f3 = std::async(std::launch::async, two_threads, vector5, vector6, std::ref(vector56), std::ref(req_time3));
        while (!is_ready(f3)) { ; }
        std::cout << req_time3.count() << "\t";
        std::future<void> f4 = std::async(std::launch::async, two_threads, vector7, vector8, std::ref(vector78), std::ref(req_time4));
        while (!is_ready(f4)) { ; }
        std::cout << req_time4.count() << std::endl;
    }
    else if (function == "four_threads") {
        std::future<void> f1 = std::async(std::launch::async, four_threads, vector1, vector2, std::ref(vector12), std::ref(req_time1));
        while (!is_ready(f1)) { ; }
        std::cout << req_time1.count() << "\t";
        std::future<void> f2 = std::async(std::launch::async, four_threads, vector3, vector4, std::ref(vector34), std::ref(req_time2));
        while (!is_ready(f2)) { ; }
        std::cout << req_time2.count() << "\t";
        std::future<void> f3 = std::async(std::launch::async, four_threads, vector5, vector6, std::ref(vector56), std::ref(req_time3));
        while (!is_ready(f3)) { ; }
        std::cout << req_time3.count() << "\t";
        std::future<void> f4 = std::async(std::launch::async, four_threads, vector7, vector8, std::ref(vector78), std::ref(req_time4));
        while (!is_ready(f4)) { ; }
        std::cout << req_time4.count() << std::endl;
    }
    else if (function == "eight_threads") {
        std::future<void> f1 = std::async(std::launch::async, eight_threads, vector1, vector2, std::ref(vector12), std::ref(req_time1));
        while (!is_ready(f1)) { ; }
        std::cout << req_time1.count() << "\t";
        std::future<void> f2 = std::async(std::launch::async, eight_threads, vector3, vector4, std::ref(vector34), std::ref(req_time2));
        while (!is_ready(f2)) { ; }
        std::cout << req_time2.count() << "\t";
        std::future<void> f3 = std::async(std::launch::async, eight_threads, vector5, vector6, std::ref(vector56), std::ref(req_time3));
        while (!is_ready(f3)) { ; }
        std::cout << req_time3.count() << "\t";
        std::future<void> f4 = std::async(std::launch::async, eight_threads, vector7, vector8, std::ref(vector78), std::ref(req_time4));
        while (!is_ready(f4)) { ; }
        std::cout << req_time4.count() << std::endl;
    }
    else if (function == "sixteen_threads") {
        std::future<void> f1 = std::async(std::launch::async, sixteen_threads, vector1, vector2, std::ref(vector12), std::ref(req_time1));
        while (!is_ready(f1)) { ; }
        std::cout << req_time1.count() << "\t";
        std::future<void> f2 = std::async(std::launch::async, sixteen_threads, vector3, vector4, std::ref(vector34), std::ref(req_time2));
        while (!is_ready(f2)) { ; }
        std::cout << req_time2.count() << "\t";
        std::future<void> f3 = std::async(std::launch::async, sixteen_threads, vector5, vector6, std::ref(vector56), std::ref(req_time3));
        while (!is_ready(f3)) { ; }
        std::cout << req_time3.count() << "\t";
        std::future<void> f4 = std::async(std::launch::async, sixteen_threads, vector7, vector8, std::ref(vector78), std::ref(req_time4));
        while (!is_ready(f4)) { ; }
        std::cout << req_time4.count() << std::endl;
    }
    else throw std::exception ("Unknown function.");
    clear_vectors(vector12, vector34, vector56, vector78);
}

int main()
{
    try {
        setlocale(LC_ALL, "Russian");
        std::mt19937 gen;
        std::uniform_int_distribution<int> dis(0, 1'000'000);
        auto rand_num([=]() mutable {return dis(gen); });

        std::vector<int> vector1(1000);
        std::vector<int> vector2(1000);
        std::vector<int> vector3(10000);
        std::vector<int> vector4(10000);
        std::vector<int> vector5(100000);
        std::vector<int> vector6(100000);
        std::vector<int> vector7(1000000);
        std::vector<int> vector8(1000000);
        std::generate(vector1.begin(), vector1.end(), rand_num);
        std::generate(vector2.begin(), vector2.end(), rand_num);
        std::generate(vector3.begin(), vector3.end(), rand_num);
        std::generate(vector4.begin(), vector4.end(), rand_num);
        std::generate(vector5.begin(), vector5.end(), rand_num);
        std::generate(vector6.begin(), vector6.end(), rand_num);
        std::generate(vector7.begin(), vector7.end(), rand_num);
        std::generate(vector8.begin(), vector8.end(), rand_num);
        std::vector<int> vector12(1000);
        std::vector<int> vector34(10000);
        std::vector<int> vector56(100000);
        std::vector<int> vector78(1000000);
        std::chrono::duration<double> req_time1;
        std::chrono::duration<double> req_time2;
        std::chrono::duration<double> req_time3;
        std::chrono::duration<double> req_time4;

        std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
        std::cout << "\t  " << "1 000" << "\t\t" << "10 000" << "\t\t" << "100 000" << "\t\t" << "1 000 000" << std::endl;

        std::cout << "1 потоков ";
        summ(vector1, vector2, vector12, req_time1, 0, vector1.size());
        summ(vector3, vector4, vector34, req_time2, 0, vector3.size());
        summ(vector5, vector6, vector56, req_time3, 0, vector5.size());
        summ(vector7, vector8, vector78, req_time4, 0, vector7.size());
        std::cout << req_time1.count() << "\t" << req_time2.count() << "\t" << req_time3.count() << "\t" << req_time4.count() << std::endl;
        clear_vectors(vector12, vector34, vector56, vector78);
        std::cout << "2 потоков ";
        calculate_and_print(vector1, vector2, vector3, vector4, vector5, vector6, vector7, vector8, vector12, vector34, vector56, vector78,
            req_time1, req_time2, req_time3, req_time4, "two_threads");
        std::cout << "4 потоков ";
        calculate_and_print(vector1, vector2, vector3, vector4, vector5, vector6, vector7, vector8, vector12, vector34, vector56, vector78,
            req_time1, req_time2, req_time3, req_time4, "four_threads");
        std::cout << "8 потоков ";
        calculate_and_print(vector1, vector2, vector3, vector4, vector5, vector6, vector7, vector8, vector12, vector34, vector56, vector78,
            req_time1, req_time2, req_time3, req_time4, "eight_threads");
        std::cout << "16 потоков ";
        calculate_and_print(vector1, vector2, vector3, vector4, vector5, vector6, vector7, vector8, vector12, vector34, vector56, vector78,
            req_time1, req_time2, req_time3, req_time4, "sixteen_threads");

        return 0;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

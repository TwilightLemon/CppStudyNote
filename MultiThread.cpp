//
// Created by TwilightLemon on 9/28/2023.
//使用C++11的多线程库简单示例
//模拟耗时操作并且获取其运算结果
//
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void Calculate(int i,int& result){
    //休眠2s
    std::this_thread::sleep_for(std::chrono::seconds(2));
    result = i+1;
}

int main() {
    const int n=5;
    auto* threads=new thread[n];
    auto* results=new int[n];
    for(int i=0;i<n;i++){
        threads[i]=thread(Calculate,i,ref(results[i]));
    }
    //此时n个线程已经开始执行

    int result=0;
    for(int i=0;i<n;i++){
        threads[i].join();//等待线程执行完毕
        result+=results[i];
    }

    delete[] threads;
    delete[] results;
    cout<<"result:"<<result;
    return 0;
}
/*
 * 有个问题：
 * 既然都向方法里传引用了，为什么不直接把result传进去让它加呢？
 * 看看Copilot如何回答的:
 * 如果你直接将result传递给每个线程，并让每个线程直接在result上累加它们的计算结果，
 * 那么你可能会遇到并发问题。因为多个线程可能会同时尝试修改result，
 * 这可能会导致数据竞争和不一致的结果。
 * 这就是为什么你需要为每个线程提供一个独立的结果变量，然后在所有线程完成后，
 * 再将这些结果合并。  如果你确实想要让每个线程直接在result上累加它们的计算结果，
 * 你需要使用某种形式的同步，例如互斥锁（std::mutex）或原子操作（std::atomic）。
 * 但是这通常会增加代码的复杂性，并可能降低性能，
 * 因为线程需要等待其他线程完成它们的更新操作。
 * */
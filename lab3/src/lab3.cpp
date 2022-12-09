#include "lab3.h"
#include "utils.h"
#include <pthread.h>
#include <iostream>

pthread_mutex_t mutex;

namespace
{

    void MinVectorT(const TVector &lhs, TVector &result, int firstSt, int lastSt, int iterator)
    {
        int min1 = lhs[firstSt];
        for (int j = firstSt; j < lastSt; ++j)
        {
            if (min1> lhs[j])
            {
                min1 = lhs[j];
            }
        }

        pthread_mutex_lock(&mutex); result[iterator] = min1;
        pthread_mutex_unlock(&mutex);
    }
}

void *MinVectorTRoutine(void *arg)
{
    auto *token = (TThreadToken *)arg;
    MinVectorT(*token->lhs, *token->result, token->firstSt, token->lastSt, token->iterator);
    return nullptr;
}

int MinVector(const TVector &lhs, int threadCount)
{
    int min;
    pthread_mutex_init(&mutex, nullptr);
    int actualThreads = std::min(threadCount, ccsize(lhs));
    TVector result(actualThreads);
    if (threadCount > 1)
    {
        int iterator = 0;
        int TPerThread = ccsize(lhs) / actualThreads;
        std::vector<pthread_t> threads(actualThreads);
        std::vector<TThreadToken> tokens(actualThreads);

        for (int i = 0; i < ccsize(lhs); i += TPerThread)
        {
            if (i + TPerThread >= ccsize(result))
            {
                tokens[iterator].lhs = &lhs;
                tokens[iterator].result = &result;
                tokens[iterator].firstSt = i;
                tokens[iterator].lastSt = ccsize(lhs);
                tokens[iterator].iterator = iterator;
                pthread_create(&threads[iterator], nullptr, &MinVectorTRoutine, &tokens[iterator]);
            }
            else
            {
                tokens[iterator].lhs = &lhs;
                tokens[iterator].result = &result;
                tokens[iterator].firstSt = i;
                tokens[iterator].lastSt = (i + TPerThread - 1);
                tokens[iterator].iterator = iterator;
                pthread_create(&threads[iterator], nullptr, &MinVectorTRoutine, &tokens[iterator]);
            }
            ++iterator;
        }
        for (int i = 0; i < actualThreads; i++)
        {
            pthread_join(threads[i], nullptr);
        }
        pthread_mutex_destroy(&mutex);
    }
    else
    {
        MinVectorT(lhs, result, 0, ccsize(lhs), 0);
    }
    min = result[0];

    for (int j = 0; j < ccsize(result); ++j)
    {
        if (min > result[j])
        {
            min =result[j];
        }
    }
    return min;
}
#include "lab3.h"
#include "utils.h"
#include <pthread.h>
#include <iostream>

namespace
{
    void MinVectorT(const TVector &lhs, TVector &result, int firstSt, int lastSt, int iterator)
    {
        int min1;
        min1 = lhs[firstSt;
        for (int j = firstSt; j < lastSt; ++j)
        {
            if (min1 > lhs[j])
            {
                min1 = lhs[j];
            }
        }
        result[iterator] = min1;
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
            tokens[iterator].lhs = &lhs;
            tokens[iterator].result = &result;
            tokens[iterator].firstSt = i;
            tokens[iterator].iterator = iterator;
            if (i + TPerThread >= ccsize(result))
            {
                tokens[iterator].lastSt = ccsize(lhs);
                pthread_create(&threads[iterator], nullptr, &MinVectorTRoutine, &tokens[iterator]);
            }
            else
            {
                tokens[iterator].lastSt = (i + TPerThread - 1);
                pthread_create(&threads[iterator], nullptr, &MinVectorTRoutine, &tokens[iterator]);
            }
            ++iterator;
        }
        for (int i = 0; i < actualThreads; i++)
        {
            pthread_join(threads[i], nullptr);
        }
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
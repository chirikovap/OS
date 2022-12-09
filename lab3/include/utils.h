#ifndef OS_LABS_UTILS_H
#define OS_LABS_UTILS_H

template <typename Container>
inline int ccsize(const Container &c)
{
    return static_cast<int>(c.size());
}

#endif 
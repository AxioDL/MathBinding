#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <CVector2f.hpp>
#include <CVector3f.hpp>
#include <CVector4f.hpp>
#include <angelscript.h>

template <class T>
class ASVector
{
public:
    ASVector()
        : d(new T),
          ownHandle(true)
    {
    }

    ASVector(float splat)
        : d(new T(splat)),
          ownHandle(true)
    {
    }

    ASVector(T& vec)
        : d(&vec),
          ownHandle(false)
    {
    }

    ASVector(const ASVector& other)
        : d(new T),
          ownHandle(true)
    {
        *d = *other.d;
    }

    ~ASVector()
    {
        if (ownHandle)
        {
            delete d;
            d = nullptr;
        }
    }

    inline ASVector& operator=(const ASVector& rhs)
    {
        if (rhs.d)
            *d = *rhs.d;
        return *this;
    }

    inline bool operator ==(const ASVector& rhs) const
    {return (*d == *rhs.d);}
    inline bool operator !=(const ASVector& rhs) const
    {return !(*this == rhs);}
    inline bool operator <(const ASVector& rhs) const
    { return *d < *rhs.d; }
    inline bool operator <=(const ASVector& rhs) const
    { return *d <= *rhs.d; }
    inline bool operator >(const ASVector& rhs) const
    { return *d > *rhs.d; }
    inline bool operator >=(const ASVector& rhs) const
    { return *d >= *rhs.d; }

    inline ASVector operator+(const ASVector& rhs) const
    {
        ASVector ret;
        *ret.d = *d + *rhs.d;
        return ret;
    }
    inline ASVector operator-(const ASVector& rhs) const
    {
        ASVector ret;
        *ret.d = *d - *rhs.d;
        return ret;
    }
    inline ASVector operator-() const
    {
        ASVector ret;
        *ret.d = -*d;
        return ret;
    }
    inline ASVector operator*(const ASVector& rhs) const
    {
        ASVector ret;
        *ret.d = (*rhs.d) * (*rhs.d);
        return ret;
    }
    inline ASVector operator/(const ASVector& rhs) const
    {
        ASVector ret;
        *ret.d = (*rhs.d) / (*rhs.d);
        return ret;
    }
    inline ASVector operator+(float val) const
    {
        ASVector ret;
        *ret.d = (*d) + val;
        return ret;
    }
    inline ASVector operator-(float val) const
    {
        ASVector ret;
        *ret.d = (*d) - val;
        return ret;
    }
    inline ASVector operator*(float val) const
    {
        ASVector ret;
        *ret.d = (*d) * val;
        return ret;
    }
    inline ASVector operator/(float val) const
    {
        ASVector ret;
        *ret.d = (*d) / val;
        return ret;
    }
    inline const ASVector& operator +=(const ASVector& rhs)
    {
        *d += *rhs.d;
        return *this;
    }
    inline const ASVector& operator -=(const ASVector& rhs)
    {
        *d -= *rhs.d;
        return *this;
    }
    inline const ASVector& operator *=(const ASVector& rhs)
    {
        *d *= *rhs.d;
        return *this;
    }
    inline const ASVector& operator /=(const ASVector& rhs)
    {
        *d /= *rhs.d;
        return *this;
    }
    inline void normalize()
    {
        d->normalize();
    }
    inline ASVector normalized() const
    {
        ASVector ret;
        *ret.d = d->normalized();
        return ret;
    }
    inline float cross(const ASVector& rhs) const
    {
        return d->cross(*rhs.d);
    }
    inline float dot(const ASVector& rhs) const
    {
        return d->dot(*rhs.d);
    }
    inline float lengthSquared() const
    {
        return d->lengthSquared();
    }
    inline float length() const
    {
        return d->length();
    }

    inline void zeroOut()
    {
        d->zeroOut();
    }

    inline void splat(float splat)
    {
        d->splat(splat);
    }

    static float getAngleDiff(const ASVector& a, const ASVector& b)
    {
        return CVector2f::getAngleDiff(*a.d, *b.d);
    }

    static inline ASVector lerp(const ASVector& a, const ASVector& b, float t)
    {
        return (a + (b - a) * t);
    }
    static inline ASVector nlerp(const ASVector& a, const ASVector& b, float t)
    {
        return lerp(a, b, t).normalized();
    }
    static ASVector slerp(const ASVector& a, const ASVector& b, float t);

    inline bool isNormalized(float thresh = 0.00001f) const
    {
        return (length() <= 1.0f + thresh);
    }

    inline float& operator[](size_t idx) {return (*d)[idx];}
    inline const float& operator[](size_t idx) const {return (*d)[idx];}


    T* d;
    bool ownHandle;
};

template <class T>
static inline ASVector<T> operator+(float lhs, const ASVector<T>& rhs)
{
    ASVector<T> ret;
    *ret.d = lhs + *rhs.d;
    return ret;
}

template <class T>
static inline ASVector<T> operator-(float lhs, const ASVector<T>& rhs)
{
    ASVector<T> ret;
    *ret.d = lhs - *rhs.d;
    return ret;
}

template <class T>
static inline ASVector<T> operator*(float lhs, const ASVector<T>& rhs)
{
    ASVector<T> ret;
    *ret.d = lhs * *rhs.d;
    return ret;
}

template <class T>
static inline ASVector<T> operator/(float lhs, const ASVector<T>& rhs)
{
    ASVector<T> ret;
    *ret.d = lhs / *rhs.d;
    return ret;
}

typedef ASVector<CVector2f> ASVector2f;
typedef ASVector<CVector3f> ASVector3f;
typedef ASVector<CVector4f> ASVector4f;

void registerVectorClasses(asIScriptEngine* engine);

#endif // VECTOR_HPP


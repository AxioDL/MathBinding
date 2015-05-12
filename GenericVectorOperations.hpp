#include <angelscript.h>
#include <CVector2f.hpp>
#include <CVector3f.hpp>
#include <CVector4f.hpp>

template <class T>
void constructVector_gen(asIScriptGeneric* gen)
{
   new(gen->GetObject()) T();
}

template <class T>
void constructVectorSplat_gen(asIScriptGeneric* gen)
{
    float splat = *(float*)(gen->GetArgAddress(0));
    new(gen->GetObject()) T(splat);
}

template <class T, int argCount>
void constructVector_coord_gen(asIScriptGeneric* gen)
{
    new(gen->GetObject()) T();
    T* obj = (T*)(gen->GetObject());
    for (int i= 0; i < argCount; ++i)
    {
        float c = *(float*)(gen->GetArgAddress(i));
        obj->d->v[i] = c;
    }
}

template <class T>
void destructVector_gen(asIScriptGeneric* gen)
{
    T* ptr = (T*)(gen->GetObject());
    if (ptr)
        ptr->~T();
}

template <class T>
void copyConstructVector_gen(asIScriptGeneric* gen)
{
    T* a = static_cast<T*>(gen->GetArgObject(0));
    new(gen->GetObject()) T(*a);
}

template <class T, class B>
void copyConstructVector2_gen(asIScriptGeneric* gen)
{
    B* a = static_cast<B*>(gen->GetArgObject(0));
    new(gen->GetObject()) T();
    T* self = (T*)gen->GetObject();
    *self->d = *a->d;
}

template <class T>
void assignVector_gen(asIScriptGeneric* gen)
{
    T* a = static_cast<T*>(gen->GetArgObject(0));
    T* self = static_cast<T*>(gen->GetObject());
    *self = *a;
    gen->SetReturnAddress(self);
}

template <class T>
void addVectors_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    T* rhs = static_cast<T*>(gen->GetArgObject(0));
    *lhs += *rhs;
    gen->SetReturnAddress(lhs);
}

template <class T>
void addVectorFloat_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    float rhs = *(float*)(gen->GetArgAddress(0));
    *lhs += rhs;
    gen->SetReturnObject(lhs);
}

template <class T>
void addVectorFloat_r_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    float rhs = *(float*)(gen->GetArgAddress(0));
    *lhs = rhs + *lhs;
    gen->SetReturnObject(lhs);
}

template <class T>
void subVectors_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    T* rhs = static_cast<T*>(gen->GetArgObject(0));
    *lhs -= *rhs;
    gen->SetReturnAddress(lhs);
}


template <class T>
void subVectorFloat_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    float rhs = *(float*)(gen->GetArgAddress(0));
    *lhs -= rhs;
    gen->SetReturnObject(lhs);
}

template <class T>
void subVectorFloat_r_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    float rhs = *(float*)(gen->GetArgAddress(0));
    *lhs = rhs - *lhs;
    gen->SetReturnObject(lhs);
}

template <class T>
void mulVectors_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    T* rhs = static_cast<T*>(gen->GetArgObject(0));
    *lhs *= *rhs;
    gen->SetReturnAddress(lhs);
}

template <class T>
void mulVectorFloat_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    float rhs = *(float*)(gen->GetArgAddress(0));
    *lhs *= rhs;
    gen->SetReturnObject(lhs);
}

template <class T>
void mulVectorFloat_r_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    float rhs = *(float*)(gen->GetArgAddress(0));
    *lhs = rhs * *lhs;
    gen->SetReturnObject(lhs);
}

template <class T>
void divVectors_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    T* rhs = static_cast<T*>(gen->GetArgObject(0));
    *lhs /= *rhs;
    gen->SetReturnAddress(lhs);
}

template <class T>
void divVectorFloat_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    float rhs = *(float*)(gen->GetArgAddress(0));
    *lhs /= rhs;
    gen->SetReturnObject(lhs);
}

template <class T>
void divVectorFloat_r_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    float rhs = *(float*)(gen->GetArgAddress(0));
    *lhs = rhs / *lhs;
    gen->SetReturnObject(lhs);
}

template <class T, int index>
static void getCoord_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    float& x = (*lhs)[index];
    gen->SetReturnAddress(&x);
}

template <class T>
void vectorIsEqual_gen(asIScriptGeneric* gen)
{
    T* lhs = static_cast<T*>(gen->GetObject());
    T* rhs = static_cast<T*>(gen->GetArgObject(0));
    *(bool*)(gen->GetAddressOfReturnLocation()) = (*lhs == *rhs);
}

template <class T>
void normalizeVec_gen(asIScriptGeneric* gen)
{
    T* lhs = (T*)(gen->GetObject());
    lhs->normalize();
}

template <class T>
void normalizedVec_gen(asIScriptGeneric* gen)
{
    T* lhs = (T*)(gen->GetObject());
    new(gen->GetAddressOfReturnLocation()) T(lhs->normalized());
}

template <class T>
void isNormalizedVec_gen(asIScriptGeneric* gen)
{
    T* lhs = (T*)(gen->GetObject());
    float thresh = *(float*)(gen->GetArgAddress(0));
    *(bool*)(gen->GetAddressOfReturnLocation()) = lhs->isNormalized(thresh);
}

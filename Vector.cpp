#include "Vector.hpp"
#include "GenericVectorOperations.hpp"

void registerVector2f(asIScriptEngine* engine);
void registerVector3f(asIScriptEngine* engine);
void registerVector4f(asIScriptEngine* engine);

void registerGenericClasses(asIScriptEngine* engine)
{
    registerVector2f(engine);
    registerVector3f(engine);
    registerVector4f(engine);
}


void registerNativeClasses(asIScriptEngine* engine)
{
}

void registerVectorClasses(asIScriptEngine* engine)
{
    //if (strstr(asGetLibraryOptions(), "AS_MAX_PORTABILITY"))
        registerGenericClasses(engine);
    /*else
        registerNativeClasses(engine);*/
}

void registerVector2f(asIScriptEngine *engine)
{
    int r;
    // Register Object
    r = engine->RegisterObjectType     ("CVector2f", sizeof(ASVector2f), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK); assert( r >= 0 );
    // Constructors & Desctructor
    r = engine->RegisterObjectBehaviour("CVector2f", asBEHAVE_CONSTRUCT, "void f()",
                                        asFUNCTION(constructVector_gen<ASVector2f>),       asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector2f", asBEHAVE_CONSTRUCT, "void f(const CVector2f& in)",
                                        asFUNCTION(copyConstructVector_gen<ASVector2f>),  asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector2f", asBEHAVE_CONSTRUCT, "void f(const float& in)",
                                        asFUNCTION(constructVectorSplat_gen<ASVector2f>),  asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector2f", asBEHAVE_CONSTRUCT, "void f(const float& in, const float& in)",
                                        asFUNCTION((constructVector_coord_gen<ASVector2f, 2>)),    asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector2f", asBEHAVE_DESTRUCT,  "void f()",
                                        asFUNCTION(destructVector_gen<ASVector2f>),       asCALL_GENERIC); assert(r >= 0);
    // Addition operators
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opAssign(const CVector2f& in)",
                                        asFUNCTION(assignVector_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opAddAssign(const CVector2f& in)",
                                        asFUNCTION(addVectors_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opAddAssign(const float& in)",
                                        asFUNCTION(addVectorFloat_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opAdd(const CVector2f& in)",
                                        asFUNCTION(addVectors_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opAdd(const float& in)",
                                        asFUNCTION(addVectorFloat_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opAdd_r(const float& in)",
                                        asFUNCTION(addVectorFloat_r_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    // Subtraction Operators
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opSubAssign(const CVector2f& in)",
                                        asFUNCTION(subVectors_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opSub(const CVector2f& in)",
                                        asFUNCTION(subVectors_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opSub(const float& in)",
                                        asFUNCTION(subVectorFloat_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opSub_r(const float& in)",
                                        asFUNCTION(subVectorFloat_r_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    // Multiplication Operators
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opMulAssign(const CVector2f& in)",
                                        asFUNCTION(mulVectors_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opMul(const CVector2f& in)",
                                        asFUNCTION(mulVectors_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opMul(const float& in)",
                                        asFUNCTION(mulVectorFloat_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opMul_r(const float& in)",
                                        asFUNCTION(mulVectorFloat_r_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    // Division Operators
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opDivAssign(const CVector2f& in)",
                                        asFUNCTION(divVectors_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opDiv(const CVector2f& in)",
                                        asFUNCTION(divVectors_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opDiv(const float& in)",
                                        asFUNCTION(divVectorFloat_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f& opDiv_r(const float& in)",
                                        asFUNCTION(divVectorFloat_r_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    // Comparison Operators
    r = engine->RegisterObjectMethod   ("CVector2f", "bool opEquals(const CVector2f& in) const",
                                        asFUNCTION(vectorIsEqual_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    // Getters & Setters
    r = engine->RegisterObjectMethod   ("CVector2f", "float& x()",
                                        asFUNCTION(getCoord_gen<0>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "float& y()",
                                        asFUNCTION(getCoord_gen<1>), asCALL_GENERIC); assert(r >= 0);
    // API Functions
    r = engine->RegisterObjectMethod   ("CVector2f", "void normalize()",
                                        asFUNCTION(normalizeVec_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "CVector2f normalized()",
                                        asFUNCTION(normalizedVec_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector2f", "bool isNormalized(const float& in=0.00001f)",
                                        asFUNCTION(isNormalizedVec_gen<ASVector2f>), asCALL_GENERIC); assert(r >= 0);
}

void registerVector3f(asIScriptEngine *engine)
{
    int r;
    // Register Object
    r = engine->RegisterObjectType     ("CVector3f", sizeof(ASVector3f), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK); assert( r >= 0 );
    // Constructors & Desctructor
    r = engine->RegisterObjectBehaviour("CVector3f", asBEHAVE_CONSTRUCT, "void f()",
                                        asFUNCTION(constructVector_gen<ASVector3f>),       asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector3f", asBEHAVE_CONSTRUCT, "void f(const CVector3f& in)",
                                        asFUNCTION(copyConstructVector_gen<ASVector3f>),  asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector3f", asBEHAVE_CONSTRUCT, "void f(const CVector2f& in)",
                                        asFUNCTION((copyConstructVector2_gen<ASVector3f, ASVector2f>)),  asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector3f", asBEHAVE_CONSTRUCT, "void f(const float& in)",
                                        asFUNCTION(constructVectorSplat_gen<ASVector3f>),  asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector3f", asBEHAVE_CONSTRUCT, "void f(const float& in, const float& in, const float& in)",
                                        asFUNCTION((constructVector_coord_gen<ASVector3f, 3>)),    asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector3f", asBEHAVE_DESTRUCT,  "void f()",
                                        asFUNCTION(destructVector_gen<ASVector3f>),       asCALL_GENERIC); assert(r >= 0);
    // Addition operators
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opAssign(const CVector3f& in)",
                                        asFUNCTION(assignVector_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opAddAssign(const CVector3f& in)",
                                        asFUNCTION(addVectors_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opAddAssign(const float& in)",
                                        asFUNCTION(addVectorFloat_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opAdd(const CVector3f& in)",
                                        asFUNCTION(addVectors_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opAdd(const float& in)",
                                        asFUNCTION(addVectorFloat_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opAdd_r(const float& in)",
                                        asFUNCTION(addVectorFloat_r_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    // Subtraction Operators
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opSubAssign(const CVector3f& in)",
                                        asFUNCTION(subVectors_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opSub(const CVector3f& in)",
                                        asFUNCTION(subVectors_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opSub(const float& in)",
                                        asFUNCTION(subVectorFloat_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opSub_r(const float& in)",
                                        asFUNCTION(subVectorFloat_r_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    // Multiplication Operators
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opMulAssign(const CVector3f& in)",
                                        asFUNCTION(mulVectors_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opMul(const CVector3f& in)",
                                        asFUNCTION(mulVectors_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opMul(const float& in)",
                                        asFUNCTION(mulVectorFloat_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opMul_r(const float& in)",
                                        asFUNCTION(mulVectorFloat_r_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    // Division Operators
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opDivAssign(const CVector3f& in)",
                                        asFUNCTION(divVectors_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opDiv(const CVector3f& in)",
                                        asFUNCTION(divVectors_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opDiv(const float& in)",
                                        asFUNCTION(divVectorFloat_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f& opDiv_r(const float& in)",
                                        asFUNCTION(divVectorFloat_r_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    // Comparison Operators
    r = engine->RegisterObjectMethod   ("CVector3f", "bool opEquals(const CVector3f& in) const",
                                        asFUNCTION(vectorIsEqual_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    // Getters & Setters
    r = engine->RegisterObjectMethod   ("CVector3f", "float& x()",
                                        asFUNCTION(getCoord_gen<0>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "float& y()",
                                        asFUNCTION(getCoord_gen<1>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "float& z()",
                                        asFUNCTION(getCoord_gen<2>), asCALL_GENERIC); assert(r >= 0);
    // API Functions
    r = engine->RegisterObjectMethod   ("CVector3f", "void normalize()",
                                        asFUNCTION(normalizeVec_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "CVector3f normalized()",
                                        asFUNCTION(normalizedVec_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector3f", "bool isNormalized(const float& in=0.00001f)",
                                        asFUNCTION(isNormalizedVec_gen<ASVector3f>), asCALL_GENERIC); assert(r >= 0);
}

void registerVector4f(asIScriptEngine *engine)
{
    int r;
    // Register Object
    r = engine->RegisterObjectType     ("CVector4f", sizeof(ASVector4f), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK); assert( r >= 0 );
    // Constructors & Desctructor
    r = engine->RegisterObjectBehaviour("CVector4f", asBEHAVE_CONSTRUCT, "void f()",
                                        asFUNCTION(constructVector_gen<ASVector4f>),       asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector4f", asBEHAVE_CONSTRUCT, "void f(const CVector4f& in)",
                                        asFUNCTION(copyConstructVector_gen<ASVector4f>),  asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector4f", asBEHAVE_CONSTRUCT, "void f(const CVector3f& in)",
                                        asFUNCTION((copyConstructVector2_gen<ASVector4f, ASVector3f>)),  asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector4f", asBEHAVE_CONSTRUCT, "void f(const float& in)",
                                        asFUNCTION(constructVectorSplat_gen<ASVector4f>),  asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector4f", asBEHAVE_CONSTRUCT, "void f(const float& in, const float& in, const float& in, const float& in)",
                                        asFUNCTION((constructVector_coord_gen<ASVector4f, 4>)),    asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectBehaviour("CVector4f", asBEHAVE_DESTRUCT,  "void f()",
                                        asFUNCTION(destructVector_gen<ASVector4f>),       asCALL_GENERIC); assert(r >= 0);
    // Addition operators
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opAssign(const CVector4f& in)",
                                        asFUNCTION(assignVector_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opAddAssign(const CVector4f& in)",
                                        asFUNCTION(addVectors_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opAddAssign(const float& in)",
                                        asFUNCTION(addVectorFloat_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opAdd(const CVector4f& in)",
                                        asFUNCTION(addVectors_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opAdd(const float& in)",
                                        asFUNCTION(addVectorFloat_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opAdd_r(const float& in)",
                                        asFUNCTION(addVectorFloat_r_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    // Subtraction Operators
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opSubAssign(const CVector4f& in)",
                                        asFUNCTION(subVectors_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opSub(const CVector4f& in)",
                                        asFUNCTION(subVectors_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opSub(const float& in)",
                                        asFUNCTION(subVectorFloat_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opSub_r(const float& in)",
                                        asFUNCTION(subVectorFloat_r_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    // Multiplication Operators
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opMulAssign(const CVector4f& in)",
                                        asFUNCTION(mulVectors_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opMul(const CVector4f& in)",
                                        asFUNCTION(mulVectors_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opMul(const float& in)",
                                        asFUNCTION(mulVectorFloat_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opMul_r(const float& in)",
                                        asFUNCTION(mulVectorFloat_r_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    // Division Operators
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opDivAssign(const CVector4f& in)",
                                        asFUNCTION(divVectors_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opDiv(const CVector4f& in)",
                                        asFUNCTION(divVectors_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opDiv(const float& in)",
                                        asFUNCTION(divVectorFloat_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f& opDiv_r(const float& in)",
                                        asFUNCTION(divVectorFloat_r_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    // Comparison Operators
    r = engine->RegisterObjectMethod   ("CVector4f", "bool opEquals(const CVector4f& in) const",
                                        asFUNCTION(vectorIsEqual_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    // Getters & Setters
    r = engine->RegisterObjectMethod   ("CVector4f", "float& x()",
                                        asFUNCTION(getCoord_gen<0>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "float& y()",
                                        asFUNCTION(getCoord_gen<1>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "float& z()",
                                        asFUNCTION(getCoord_gen<2>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "float& w()",
                                        asFUNCTION(getCoord_gen<3>), asCALL_GENERIC); assert(r >= 0);
    // API Functions
    r = engine->RegisterObjectMethod   ("CVector4f", "void normalize()",
                                        asFUNCTION(normalizeVec_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "CVector4f normalized()",
                                        asFUNCTION(normalizedVec_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
    r = engine->RegisterObjectMethod   ("CVector4f", "bool isNormalized(const float& in=0.00001f)",
                                        asFUNCTION(isNormalizedVec_gen<ASVector4f>), asCALL_GENERIC); assert(r >= 0);
}

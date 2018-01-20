#ifndef CML_REAL_H
#define CML_REAL_H


typedef struct _real
{

        mfloat_t real_value;

        #ifndef CML_NO_FUNCTION_POINTER
        mfloat_t (*value)(struct _real *);
        void (*setValue)(struct _real *, mfloat_t);
        char * (*asString)(struct _real *);

        bool (*equals)(struct _real *, struct _real *);
        bool (*isNull)(struct _real *);
        bool (*isGreater)(struct _real *, struct _real *);
        bool (*isLess)(struct _real *, struct _real *);
        bool (*isGreaterOrEquals)(struct _real *, struct _real *);
        bool (*isLessOrEquals)(struct _real *, struct _real *);
        bool (*isNatural)(struct _real *);
        bool (*isInteger)(struct _real *);
        bool (*isMult)(struct _real *, struct _real *);

        struct _real * (*add)(struct _real *, struct _real *);
        struct _real * (*prod)(struct _real *, struct _real *);
        struct _real * (*sgn)(struct _real *);
        struct _real * (*abs)(struct _real *);
        struct _real * (*sub)(struct _real *, struct _real *);
        struct _real * (*div)(struct _real *, struct _real *);
        struct _real * (*divE)(struct _real *, struct _real *);
        struct _real * (*mod)(struct _real *, struct _real *);
        struct _real * (*inverse)(struct _real *);
        struct _real * (*opposite)(struct _real *);
        struct _real * (*ared)(struct _real *);
        struct _real * (*fact)(struct _real *);
        struct _real * (*ceil)(struct _real *);
        struct _real * (*floor)(struct _real *);

        struct _real * (*exp)(struct _real *);
        struct _real * (*ln)(struct _real *);
        struct _real * (*logE)(struct _real *);
        struct _real * (*logB)(struct _real *, struct _real *);
        struct _real * (*pow)(struct _real *, struct _real *);
        struct _real * (*root)(struct _real *, struct _real *);
        struct _real * (*sqrt)(struct _real *);

        struct _real * (*sin)(struct _real *);
        struct _real * (*cos)(struct _real *);
        struct _real * (*tan)(struct _real *);
        struct _real * (*sec)(struct _real *);
        struct _real * (*csc)(struct _real *);
        struct _real * (*cot)(struct _real *);
        struct _real * (*asin)(struct _real *);
        struct _real * (*acos)(struct _real *);
        struct _real * (*atan)(struct _real *);
        struct _real * (*atan2)(struct _real *, struct _real *);

        struct _real * (*sinh)(struct _real *);
        struct _real * (*cosh)(struct _real *);
        struct _real * (*tanh)(struct _real *);
        struct _real * (*sech)(struct _real *);
        struct _real * (*csch)(struct _real *);
        struct _real * (*coth)(struct _real *);
        struct _real * (*asinh)(struct _real *);
        struct _real * (*acosh)(struct _real *);
        struct _real * (*atanh)(struct _real *);

        void (*free)(struct _real *);
        #endif
} real_t;

typedef real_t* real;

real_t _real_create(mfloat_t);

// Construct & destruct
real _real_new(mfloat_t);
void _real_free(real);

real _real_clone(real);

// Initialization
void init_real(real);

// getters
mfloat_t real_value(real);

// setters
void real_set_value(real, mfloat_t);

// Methods
char * real_as_string(real);

#endif

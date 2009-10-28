#ifdef NA3D_EXPORTS
#define NA3D_API __declspec(dllexport)
#else
#define NA3D_API __declspec(dllimport)
#endif
#ifndef S2MIMU_UNITY_OPTIM_H
#define S2MIMU_UNITY_OPTIM_H
#include <dlib/optimization.h>  
#include "s2mAttitude.h" 

class s2mIMU_Unity_Optim
{
    public:
        typedef dlib::matrix<double,1,1> parameter_vector;
        class OptimData{
        public:
            OptimData(const s2mAttitude &R1, const s2mAttitude &R2, int axe);
            s2mAttitude m_R1;
            s2mAttitude m_R2;
            int m_axe;
        };
        static s2mAttitude alignSpecificAxisWithParentVertical(const s2mAttitude &r1, const s2mAttitude &r2, int idxAxe); // Optimization

    protected:
		static double residual (const OptimData& data, const parameter_vector& x); // Optimization

    private:
};

#endif // S2MIMU_UNITY_OPTIM_H

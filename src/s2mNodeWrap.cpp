#include "../include/s2mNodeWrap.h"

s2mNodeWrap::s2mNodeWrap(const Eigen::Vector3d &v,
                         const s2mString &name,
                         const s2mString &parentName) :
    s2mNode(v, name,parentName)
{
}

s2mNodeWrap::~s2mNodeWrap()
{
    //dtor
}

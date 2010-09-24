#ifndef _ZSORTABLE_H_
#define _ZSORTABLE_H_

namespace lite
{
    class IHasZ
    {
        virtual float z() const = 0;
        virtual z(float value) const = 0;
    }

} // namespace lite

#endif

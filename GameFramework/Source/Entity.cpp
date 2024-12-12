
#include "../Include/HeaderLib.h"

namespace MichGF
{
	void CEntity::vAddComponent(std::shared_ptr<CComponent> pComponent)
	{
		pComponent->vSetEntity(this);
		m_lComponents.push_back(pComponent);
	}
}

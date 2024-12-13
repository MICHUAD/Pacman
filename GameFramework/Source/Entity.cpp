
#include "../Include/HeaderLib.h"

namespace MichGF
{
	std::shared_ptr<CEntity> CEntity::getEntity(const std::string& sName, CScene sScene)
	{
		for (const auto& pEntity : sScene.getEntities<CEntity>())
		{
			if (pEntity->sGetName() == sName)
			{
				return pEntity;
			}
		}
	}
	void CEntity::vAddComponent(std::shared_ptr<CComponent> pComponent)
	{
		pComponent->vSetEntity(this);
		m_lComponents.push_back(pComponent);
	}
}

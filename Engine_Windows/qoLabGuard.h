#pragma once
#include "qoEnemy.h"

namespace qo
{
	class LabGuard : public Enemy
	{
	public:
		LabGuard();
		virtual ~LabGuard();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetStatus(Vector3 Position) { Pos = Position; }
		void SetPlayer(GameObject* player);

		virtual void Search() override;
		virtual void Chase() override;
		virtual void Attack() override;
		virtual void Dead() override;
		virtual void TakeHit(int DamageAmount, math::Vector3 HitDir = Vector3::Zero) override;

		Vector3 Pos;

		class Player* mPlayer;
	private:
	};
}


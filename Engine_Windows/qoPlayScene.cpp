#include "qoPlayScene.h"
#include "qoResourceManager.h"
#include "qoCollisionManager.h"

#include "qoGameObject.h"
#include "qoTransform.h"
#include "qoMeshRenderer.h"
#include "qoCollider.h"
#include "qoRigidbody.h"
#include "qoPlayerScript.h"
#include "qoPlayer.h"
#include "qofloor.h"
#include "qoRigidbody.h"
#include "qoCamera.h"

#include "ArchitectureInclude.h"

namespace qo
{
	PlayScene::PlayScene()
	{
	}


	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{		
		Player* player = new Player();
		Transform* PlayerTransform = player->AddComponent<Transform>();
		PlayerTransform->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		PlayerTransform->SetScale(Vector3(0.1f, 0.3f, 0.f));
		PlayerTransform->SetColor(Vector4(0.f, 0.f, 1.f, 0.f));

		MeshRenderer* PlayerMeshRenderer = player->AddComponent<MeshRenderer>();
		PlayerMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectangleMesh"));
		PlayerMeshRenderer->SetShader(ResourceManager::Find<Shader>(L"ColorTestShader"));	

		Collider* PlayerCollider = player->AddComponent<Collider>();
		PlayerCollider->SetScale(Vector3(0.1f, 0.3f, 0.f));
					 
		player->AddComponent<Rigidbody>();
		
		player->AddComponent<PlayerScript>();

		// �� ����
		player->AddGun(eGunType::Superposition);
		player->AddGun(eGunType::Entanglement);
		player->AddGun(eGunType::Teleportation);

		player->ChangeActiveGun(eGunType::Superposition);

		player->Initialize();

		AddGameObject(player, LAYER::PLAYER);
		Camera::SetTarget(player);


		// �ٴ� ��ü ����
		Floor* ground = new Floor();
		Transform* GroundTransform = ground->AddComponent<Transform>();
		GroundTransform->SetPosition(Vector3(0.0f, -0.5f, 0.0f));
		GroundTransform->SetScale(Vector3(1.f, 0.3f, 0.0f));
		GroundTransform->SetColor(Vector4(0.5f, 0.5f, 0.5f, 0.f));

		MeshRenderer* GroundMeshRenderer = ground->AddComponent<MeshRenderer>();
		GroundMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectangleMesh"));
		GroundMeshRenderer->SetShader(ResourceManager::Find<Shader>(L"ColorTestShader")); 

		Collider* GroundCollider = ground->AddComponent<Collider>();
		GroundCollider->SetScale(Vector3(1.f, 0.3f, 0.f));

		AddGameObject(ground, LAYER::FLOOR);

		CollisionManager::CollisionLayerCheck(LAYER::PLAYER, LAYER::FLOOR, TRUE);

		// �� ������Ʈ ����
		Wall* wall = new Wall();
		Transform* WallTransform = wall->AddComponent<Transform>();
		WallTransform->SetPosition(Vector3(0.5f, 0.0f, 0.0f));
		WallTransform->SetScale(Vector3(0.3f, 1.f, 0.0f));
		WallTransform->SetColor(Vector4(0.3f, 0.3f, 0.3f, 0.f));

		MeshRenderer* WallMeshRenderer = wall->AddComponent<MeshRenderer>();
		WallMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectangleMesh"));
		WallMeshRenderer->SetShader(ResourceManager::Find<Shader>(L"ColorTestShader"));

		Collider* WallCollider = wall->AddComponent<Collider>();
		WallCollider->SetScale(Vector3(0.3f, 1.f, 0.0f));

		AddGameObject(wall, LAYER::WALL);

		CollisionManager::CollisionLayerCheck(LAYER::PLAYER, LAYER::WALL, TRUE);

		CollisionManager::CollisionLayerCheck(LAYER::BULLET, LAYER::WALL, TRUE);
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render()
	{
		Scene::Render();
	}
}

## Sobre
Unreal Engine é um motor de jogo desenvolvido pela Epic Games, usado pela primeira vez em 1998 no jogo de tiro em primeira pessoa Unreal, ele tem sido a base de muitos jogos desde então. Embora usado inicialmente para jogos de tiro em primeira pessoa, ele tem sido usado com sucesso em uma grande variedade de gêneros de jogos.

Seu núcleo é escrito em C++, possibilitando a portabilidade. Suporta múltiplas plataformas, incluindo Microsoft Windows, Linux, Mac OS e Mac OS X em computadores pessoais, e os consoles Dreamcast, GameCube, Nintendo Switch, PlayStation 2, PlayStation 3, PlayStation 4, PlayStation 5, Stadia, Wii, Wii U, Xbox, Xbox 360, Xbox One e Xbox Series X.

## Instalação

## Unreal Engine
### Controlando a ViewPort
Pode se ter mais de um viewport. É bem útil quando se esta trabalhando em mais de um Level. Para ativar outras pode se ir em **Window** > **ViewPorts**.

![teste](/estudo/unreal/imagens/1.png)

### Actor e Components
- Um Actor é um container que pode ter muitos Components
- Existem muitos tipos diferentes de Components

### Unreal C++ Types
O Unreal tem seus próprios tipos.
Tipo C++ | Tipo Unreal
--- | ---
```std::string``` | ```FString```
```int``` | ```int32```

### Adicionando cabeçalho de Copyright
É possível adicionar cabeçalhos automaticos de Copyright aos seus arquivos criados.
Para isso deve se ir em **Edit** > **Project Settings**.

![teste](/estudo/unreal/imagens/4.png)

Depois em **Project** > **Description** e colocar a mensagem de copyright em **Copyright Notice**

![teste](/estudo/unreal/imagens/5.png)

### Classes e componentes
Após adicionar um objeto na cena, podemos selecionar ele, e depois ir em **+Add Component** > **New C++ Component**.

![teste](/estudo/unreal/imagens/2.png)

Selecione **Actor Component** e depois clique em **Next**. Finalmente coloque o nome da classe clique em **Create Class**.

![teste](/estudo/unreal/imagens/3.png)

Nesse exemplo será utilizado **Teste** como nome da classe.
Com isso teremos os seguintes arquivos criados:
> Teste.h
```c++
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Teste.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UTeste : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTeste();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
```
É importante ressaltar que a linha de include da sua propria classe ```SuaClasse.generate.h``` deve sempre ficar abaixo das inclusões das classes do Unreal.
```c++
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Teste.generated.h" // Sempre abaixo
```
> Teste.cpp
```c++
// Fill out your copyright notice in the Description page of Project Settings.


#include "Teste.h"

// Sets default values for this component's properties
UTeste::UTeste()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTeste::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UTeste::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


```
O método ```BeginPlay()``` é chamado sempre que o jogo começa.

O método ```TickComponent()``` é chamado a cada quadro do jogo.

No método construtor, a instrução ```PrimaryComponentTick.bCanEverTick = true;``` indica que o método ```TickComponent``` sempre será chamado a cada quadro. É possível desativar atribuindo como ```false```.

### Deletando uma classe
É preciso navegar até onde o projeto está localizado e excluir os arquivos manualmente. Eles ficam em ```.../raiz_do_projeto/Source/NomeDoProjeto/```

Depois é necessário apagar o diretorio **Binaries** que fica em ```.../raiz_do_projeto/Binaries```. Lembre-se de fechar o UnrealEngine antes.

Abra o UnrealEngine novamente e você devera ver a seguinte mensagem, no qual devera clicar em sim, depois de abrir seu projeto:

<div align='center'>
  <img src="imagens/6.png">
</div>

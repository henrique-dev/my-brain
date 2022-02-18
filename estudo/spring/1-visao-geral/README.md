## Spring Framework

O Spring é um framework Java criado com o objetivo de facilitar o desenvolvimento de aplicações, explorando, para isso, os conceitos de Inversão de Controle e Injeção de Dependências. Dessa forma, ao adotá-lo, temos à nossa disposição uma tecnologia que nos fornece não apenas recursos necessários à grande parte das aplicações, como módulos para persistência de dados, integração, segurança, testes, desenvolvimento web, como também um conceito a seguir que nos permite criar soluções menos acopladas, mais coesas e, consequentemente, mais fáceis de compreender e manter.

## Por que o Spring foi criado?

O Spring foi criado por causa das dificuldades que os programadores enfrentavam ao criar determinado tipo de aplicação, mais precisamente, aplicações corporativas. Na época, a plataforma Java voltada para isso, de nome J2EE, ainda era jovem, com ótimas ideias para a construção de aplicações leves, distribuídas, com um amplo leque de opções/ferramentas, mas com algumas limitações. Essas limitações levavam a uma programação dependente de muitas interfaces e com muitas configurações. Ao final, era comum ter uma solução pesada e que trazia consigo muito mais do que o que realmente era necessário.

E para completar, precisávamos utilizar servidores de aplicação pesados, o que tornava a programação e a depuração das aplicações ainda mais lento.

## Características do Spring Framework

Seguindo um caminho diferente, em pouco tempo o Spring conquistou seu espaço na comunidade. Mas, que caminho diferente foi esse?

- A primeira diferença é que ele não precisa de um servidor de aplicação para funcionar. Fazendo uso apenas da JVM, o Spring traz para o programador recursos que antes só estavam disponíveis para soluções corporativas;
- Com Spring também passamos a utilizar apenas aquilo que é necessário para o projeto. Como mencionado agora há pouco, a plataforma J2EE e os EJBs nos levavam a implementar comportamentos que não eram necessários. Esse diferencial do Spring torna a arquitetura mais leve, fácil de compreender, manter e evoluir;
- Outro diferencial é que ele é baseado na inversão de controle e injeção de dependência, fornecendo para isso um container, que representa o núcleo do framework e que é responsável por criar e gerenciar os componentes da aplicação, os quais são comumente chamados de beans.

## Objetivos do Spring
- Desenvolvimento simplificado com Java POJOs (Plain-Old-Java-Objects)
- Injeção de dependência para promover desacomplamento
- Programção declarativa com AOP (Aspect-Oriented-Programming)
- Minimizar o código escrito em Java

## Módulos
O Spring Framework consiste em recursos organizados em cerca de 20 módulos. Esses módulos são agrupados em Core Container, Data Access/Integration, Web, AOP (Aspect Oriented Programming), Instrumentation, Messaging e Test, conforme mostrado no diagrama a seguir.

![](https://docs.spring.io/spring-framework/docs/4.3.x/spring-framework-reference/html/images/spring-overview.png)

### Core Container: Beans, Core, SpEL e Context

O Core Container consiste nos módulos spring-core, spring-beans, spring-context, spring-context-support e spring-expression (Spring Expression Language).

Os módulos spring-core e spring-beans fornecem as partes fundamentais da estrutura, incluindo os recursos de IoC e injeção de dependência. O BeanFactory é uma implementação sofisticada do padrão de fábrica. Ele elimina a necessidade de singletons programáticos e permite desacoplar a configuração e a especificação de dependências da lógica real do programa.

O módulo Context (spring-context) baseia-se na base sólida fornecida pelos módulos Core e Beans: é um meio de acessar objetos de maneira semelhante a um registro JNDI. O módulo Context herda seus recursos do módulo Beans e adiciona suporte para internacionalização (usando, por exemplo, pacotes de recursos), propagação de eventos, carregamento de recursos e criação transparente de contextos por, por exemplo, um contêiner Servlet. O módulo Context também suporta recursos Java EE, como EJB, JMX e comunicação remota básica. A interface ApplicationContext é o ponto focal do módulo Context. spring-context-support fornece suporte para integração de bibliotecas comuns de terceiros em um contexto de aplicativo Spring para armazenamento em cache (EhCache, Guava, JCache), correspondência (JavaMail), agendamento (CommonJ, Quartz) e mecanismos de modelo (FreeMarker, JasperReports, Velocity).

E o módulo spring-expression fornece uma linguagem de expressão poderosa para consultar e manipular um gráfico de objeto em tempo de execução. É uma extensão da linguagem de expressão unificada (EL unificado) conforme especificado na especificação JSP 2.1. A linguagem suporta a configuração e obtenção de valores de propriedades, atribuição de propriedades, invocação de métodos, acesso ao conteúdo de arrays, coleções e indexadores, operadores lógicos e aritméticos, variáveis nomeadas e recuperação de objetos por nome do contêiner IoC do Spring. Ele também suporta projeção e seleção de listas, bem como agregações de listas comuns.

### Infraestrutura: AOP, Aspects, Instrumentation and Messaging
O módulo spring-aop fornece uma implementação de programação orientada a aspectos compatível com AOP Alliance, permitindo que você defina, por exemplo, interceptores de método e pontos de corte para desacoplar de maneira limpa o código que implementa a funcionalidade que deve ser separada. Usando a funcionalidade de metadados de nível de origem, você também pode incorporar informações comportamentais em seu código, de maneira semelhante à dos atributos .NET.

O módulo separado spring-aspects fornece integração com o AspectJ.

O módulo spring-instrument fornece suporte de instrumentação de classe e implementações de carregador de classe para serem usados em determinados servidores de aplicativos. O módulo spring-instrument-tomcat contém o agente de instrumentação do Spring para Tomcat.

O Spring Framework 4 inclui o módulo spring-messaging com abstrações-chave do projeto Spring Integration, como Message, MessageChannel, MessageHandler e outros, para servir como base para aplicativos baseados em mensagens. O módulo também inclui um conjunto de anotações para mapeamento de mensagens para métodos, semelhante ao modelo de programação baseado em anotações Spring MVC.

### Integração e Acesso aos Dados: JDBC, ORM, Transactions, OXM e JMS
A camada Acesso/Integração de dados consiste nos módulos JDBC, ORM, OXM, JMS e Transactions.

O módulo spring-jdbc fornece uma camada de abstração JDBC que elimina a necessidade de codificação JDBC tediosa e análise de códigos de erro específicos do fornecedor do banco de dados.

O módulo spring-tx suporta gerenciamento de transações programáticas e declarativas para classes que implementam interfaces especiais e para todos os seus POJOs (Plain Old Java Objects).

O módulo spring-orm fornece camadas de integração para APIs populares de mapeamento relacional de objeto, incluindo JPA, JDO e Hibernate. Usando o módulo spring-orm, você pode usar todas essas estruturas de mapeamento O/R em combinação com todos os outros recursos que o Spring oferece, como o recurso de gerenciamento de transação declarativo simples mencionado anteriormente.

O módulo spring-oxm fornece uma camada de abstração que suporta implementações de mapeamento Object/XML como JAXB, Castor, XMLBeans, JiBX e XStream.

O módulo spring-jms (Java Messaging Service) contém recursos para produzir e consumir mensagens. Desde o Spring Framework 4.1, ele fornece integração com o módulo spring-messaging.

### Web: Servlet, WebSocket, Web e Portlet
A camada da Web consiste nos módulos spring-web, spring-webmvc, spring-websocket e spring-webmvc-portlet.

O módulo spring-web fornece recursos básicos de integração orientados para a web, como a funcionalidade de upload de arquivos multipartes e a inicialização do contêiner IoC usando ouvintes de Servlet e um contexto de aplicativo orientado para a web. Ele também contém um cliente HTTP e as partes relacionadas à web do suporte remoto do Spring.

O módulo spring-webmvc (também conhecido como módulo Web-Servlet) contém o model-view-controller (MVC) do Spring e a implementação de serviços Web REST para aplicativos da web. A estrutura MVC do Spring fornece uma separação clara entre o código do modelo de domínio e os formulários da web e se integra a todos os outros recursos do Spring Framework.

O módulo spring-webmvc-portlet (também conhecido como módulo Web-Portlet) fornece a implementação MVC a ser usada em um ambiente de Portlet e espelha a funcionalidade do módulo spring-webmvc baseado em Servlet.

### Testes
O módulo spring-test suporta o teste de unidade e teste de integração de componentes Spring com JUnit ou TestNG. Ele fornece carregamento consistente de Spring ApplicationContexts e armazenamento em cache desses contextos. Ele também fornece objetos simulados que você pode usar para testar seu código isoladamente.

## Projetos Spring
São módulos adicionais integrados no Spring Core. São eles:

### Spring Boot
O Spring Boot facilita a criação de aplicativos independentes baseados em Spring de nível de produção que você pode "apenas executar".

Temos uma visão opinativa da plataforma Spring e das bibliotecas de terceiros para que você possa começar com o mínimo de barulho. A maioria dos aplicativos Spring Boot precisa de configuração mínima do Spring.
- Crie aplicativos Spring independentes
- Incorpore o Tomcat, Jetty ou Undertow diretamente (sem necessidade de implantar arquivos WAR)
- Forneça dependências 'iniciais' opinativas para simplificar sua configuração de compilação
- Configure automaticamente bibliotecas Spring e de terceiros sempre que possível
- Forneça recursos prontos para produção, como métricas, verificações de integridade e configuração externa
- Absolutamente nenhuma geração de código e nenhum requisito para configuração XML

### Spring data
A missão da Spring Data é fornecer um modelo de programação familiar e consistente baseado em Spring para acesso a dados, mantendo as características especiais do armazenamento de dados subjacente.

Facilita o uso de tecnologias de acesso a dados, bancos de dados relacionais e não relacionais, estruturas de redução de mapa e serviços de dados baseados em nuvem. Este é um projeto guarda-chuva que contém muitos subprojetos específicos para um determinado banco de dados. Os projetos são desenvolvidos trabalhando em conjunto com muitas das empresas e desenvolvedores que estão por trás dessas tecnologias interessantes.
- Repositório poderoso e abstrações de mapeamento de objeto personalizado
- Derivação de consulta dinâmica de nomes de métodos de repositório
- Classes base de domínio de implementação que fornecem propriedades básicas
- Suporte para auditoria transparente (criado, alterado pela última vez)
- Possibilidade de integrar código de repositório personalizado
- Integração fácil do Spring via JavaConfig e namespaces XML personalizados
- Integração avançada com controladores Spring MVC
- Suporte experimental para persistência entre lojas

### Spring Cloud
Spring Cloud fornece ferramentas para desenvolvedores para construir rapidamente alguns dos padrões comuns em sistemas distribuídos (por exemplo, gerenciamento de configuração, descoberta de serviço, disjuntores, roteamento inteligente, micro-proxy, barramento de controle, tokens únicos, bloqueios globais, eleição de liderança, distribuição sessões, estado do cluster). A coordenação de sistemas distribuídos leva a padrões de boilerplate e, usando o Spring Cloud, os desenvolvedores podem criar rapidamente serviços e aplicativos que implementam esses padrões. Eles funcionarão bem em qualquer ambiente distribuído, incluindo o próprio laptop do desenvolvedor, data centers bare metal e plataformas gerenciadas, como Cloud Foundry.
- Configuração distribuída/versão
- Registro e descoberta de serviços
- Roteamento
- Chamadas de serviço a serviço
- Balanceamento de carga
- Disjuntores
- Bloqueios globais
- Eleição de liderança e estado de cluster
- Mensagens distribuídas

### Spring Cloud Data Flow
Processamento de dados em lote e streaming baseado em microsserviços para Cloud Foundry e Kubernetes.

O Spring Cloud Data Flow fornece ferramentas para criar topologias complexas para pipelines de dados em lote e streaming. Os pipelines de dados consistem em aplicativos Spring Boot, criados usando as estruturas de microsserviço Spring Cloud Stream ou Spring Cloud Task.

O Spring Cloud Data Flow oferece suporte a uma variedade de casos de uso de processamento de dados, de ETL a importação/exportação, streaming de eventos e análise preditiva.

O servidor Spring Cloud Data Flow usa o Spring Cloud Deployer para implantar pipelines de dados feitos de aplicativos Spring Cloud Stream ou Spring Cloud Task em plataformas modernas, como Cloud Foundry e Kubernetes.

Uma seleção de aplicativos iniciais de fluxo e tarefa/lote pré-criados para vários cenários de integração e processamento de dados facilitam o aprendizado e a experimentação.

Aplicativos personalizados de fluxo e tarefa, direcionados a diferentes middleware ou serviços de dados, podem ser construídos usando o modelo de programação familiar no estilo Spring Boot.

Um DSL de pipeline de fluxo simples facilita a especificação de quais aplicativos implantar e como conectar saídas e entradas. A tarefa composta DSL é útil para quando uma série de aplicativos de tarefas precisam ser executados como um gráfico direcionado.

O painel oferece um editor gráfico para criar pipelines de dados interativamente, bem como visualizações de aplicativos implantáveis ​​e monitorá-los com métricas usando Wavefront, Prometheus, Influx DB ou outros sistemas de monitoramento.

O servidor Spring Cloud Data Flow expõe uma API REST para compor e implantar pipelines de dados. Um shell separado facilita o trabalho com a API a partir da linha de comando.

### Spring Security
Spring Security é uma poderosa e altamente personalizável estrutura de autenticação e controle de acesso. É o padrão de fato para proteger aplicativos baseados em Spring.

Spring Security é uma estrutura que se concentra em fornecer autenticação e autorização para aplicativos Java. Como todos os projetos do Spring, o verdadeiro poder do Spring Security é encontrado na facilidade com que ele pode ser estendido para atender aos requisitos personalizados
- Suporte abrangente e extensível para autenticação e autorização
- Proteção contra ataques como fixação de sessão, clickjacking, falsificação de solicitação entre sites, etc.
- Integração de API de servlet
- Integração opcional com Spring Web MVC

### Spring for GraphQL
Spring para GraphQL fornece suporte para aplicativos Spring construídos em GraphQL Java. É uma colaboração conjunta entre as duas equipes. Nossa filosofia compartilhada é ser menos opinativo e mais focado no suporte abrangente e abrangente.

Spring for GraphQL é o sucessor do projeto GraphQL Java Spring da equipe GraphQL Java. Ele pretende ser a base para todos os aplicativos Spring, GraphQL.

### Spring Session
Fornece uma API e implementações para gerenciar as informações de sessão de um usuário.

O Spring Session torna trivial o suporte a sessões em cluster sem estar vinculado a uma solução específica de contêiner de aplicativo. Ele também fornece integração transparente com:
- HttpSession - permite substituir a HttpSession em um contêiner de aplicação (ou seja, Tomcat) de maneira neutra, com suporte para fornecer IDs de sessão em cabeçalhos para trabalhar com APIs RESTful
- WebSocket - fornece a capacidade de manter a HttpSession ativa ao receber mensagens WebSocket
- WebSession - permite substituir a WebSession do Spring WebFlux de uma forma neutra de container de aplicação

### Spring Integration
Estende o modelo de programação Spring para suportar os conhecidos padrões de integração empresarial. O Spring Integration permite mensagens leves em aplicativos baseados em Spring e suporta integração com sistemas externos por meio de adaptadores declarativos. Esses adaptadores fornecem um nível mais alto de abstração sobre o suporte do Spring para comunicação remota, mensagens e agendamento. O objetivo principal do Spring Integration é fornecer um modelo simples para construir soluções de integração corporativa, mantendo a separação de interesses que é essencial para a produção de código passível de manutenção e testável.

O uso do Spring Framework incentiva os desenvolvedores a codificar usando interfaces e usar injeção de dependência (DI) para fornecer um Plain Old Java Object (POJO) com as dependências necessárias para executar suas tarefas. O Spring Integration leva esse conceito um passo adiante, onde POJOs são conectados usando um paradigma de mensagens e componentes individuais podem não estar cientes de outros componentes no aplicativo. Esse aplicativo é construído pela montagem de componentes reutilizáveis ​​de granulação fina para formar um nível mais alto de funcionalidade. Com um design cuidadoso, esses fluxos podem ser modularizados e também reutilizados em um nível ainda mais alto.

Além de conectar componentes refinados, o Spring Integration fornece uma ampla seleção de adaptadores de canal e gateways para comunicação com sistemas externos. Adaptadores de canal são usados ​​para integração unidirecional (enviar ou receber); gateways são usados ​​para cenários de solicitação/resposta (entrada ou saída). Para obter uma lista completa de adaptadores e gateways, consulte a documentação de referência.
- Implementação da maioria dos padrões de integração empresarial
- Endpoint
- Channel (Point-to-point and Publish/Subscribe)
- Aggregator
- Filter
- Transformer
- Control Bus
- Integration with External Systems
- ReST/HTTP
- FTP/SFTP
- STOMP
- WebServices (SOAP and ReST)
- TCP/UDP
- JMS
- RabbitMQ
- Email
- O framework possui amplo suporte a JMX
- Expondo componentes da estrutura como MBeans
- Adaptadores para obter atributos de MBeans, invocar operações, enviar/receber notificações

### Spring HATEOAS
Spring HATEOAS fornece algumas APIs para facilitar a criação de representações REST que seguem o princípio HATEOAS ao trabalhar com Spring e especialmente Spring MVC. O problema central que ele tenta resolver é a criação de links e a montagem de representações.
- Classes de modelo para link, modelos de representação de recursos
- API do construtor de links para criar links apontando para métodos do controlador Spring MVC
- Suporte para formatos hipermídia como HAL

### Spring REST Docs
Spring REST Docs ajuda você a documentar serviços RESTful.

Ele combina documentação escrita à mão escrita com Asciidoctor e trechos gerados automaticamente produzidos com Spring MVC Test. Essa abordagem libera você das limitações da documentação produzida por ferramentas como o Swagger.

Ele ajuda você a produzir documentação precisa, concisa e bem estruturada. Essa documentação permite que seus usuários obtenham as informações de que precisam com o mínimo de confusão.

### Spring Batch
Uma estrutura de lote leve e abrangente projetada para permitir o desenvolvimento de aplicativos de lote robustos vitais para as operações diárias dos sistemas corporativos.

O Spring Batch fornece funções reutilizáveis que são essenciais no processamento de grandes volumes de registros, incluindo log/rastreamento, gerenciamento de transações, estatísticas de processamento de tarefas, reinicialização de tarefas, pular e gerenciamento de recursos. Ele também fornece serviços e recursos técnicos mais avançados que permitirão trabalhos em lote de alto volume e alto desempenho por meio de técnicas de otimização e particionamento. Trabalhos em lote simples e complexos de alto volume podem aproveitar a estrutura de maneira altamente escalável para processar volumes significativos de informações.
- Gerenciamento de transações
- Processamento baseado em chunks
- E/S declarativa
- Iniciar/Parar/Reiniciar
- Repetir/Pular
- Interface de administração baseada na Web (Spring Cloud Data Flow)

### Spring AMQP
O projeto Spring AMQP aplica os conceitos básicos do Spring ao desenvolvimento de soluções de mensagens baseadas em AMQP. Ele fornece um "modelo" como uma abstração de alto nível para enviar e receber mensagens. Ele também fornece suporte para POJOs acionados por mensagens com um "contêiner de ouvinte". Essas bibliotecas facilitam o gerenciamento de recursos AMQP enquanto promovem o uso de injeção de dependência e configuração declarativa. Em todos esses casos, você verá semelhanças com o suporte JMS no Spring Framework.

O projeto consiste em duas partes; spring-amqp é a abstração base e spring-rabbit é a implementação do RabbitMQ.
- Contêiner de ouvinte para processamento assíncrono de mensagens de entrada
- RabbitTemplate para enviar e receber mensagens
- RabbitAdmin para declarar automaticamente filas, trocas e ligações

### Spring CredHub
O Spring CredHub fornece suporte do lado do cliente para armazenar, recuperar e excluir credenciais de um servidor CredHub em execução em uma plataforma Cloud Foundry.

O CredHub fornece uma API para armazenar, gerar, recuperar e excluir com segurança credenciais de vários tipos. O Spring CredHub fornece uma ligação Java para a API do CredHub, facilitando a integração de aplicativos Spring com o CredHub.

### Spring Flo
Spring Flo é uma biblioteca JavaScript que oferece um construtor visual HTML5 básico incorporável para pipelines e gráficos simples. Essa biblioteca é usada como base do construtor de fluxo no Spring Cloud Data Flow.

Flo inclui todos os elementos básicos de um designer de fluxo de integração, como conectores, nós de controle, paletas, transições de estado e topologias gráficas - é importante que haja um shell textual, suporte DSL e uma tela gráfica projetada para criar e revisar fluxos de trabalho abrangentes .
- Crie, gerencie e monitore pipelines de fluxo usando DSL, uma tela gráfica ou ambos
- Escreva pipelines via DSL com assistência de conteúdo e preenchimento automático
- Veja uma representação visual de módulos em uma implantação distribuída
- Use recursos de ajuste automático e layout de grade na GUI para uma organização de pipelines mais fácil e eficiente

### Spring for Apache Kafka
O projeto Spring para Apache Kafka (spring-kafka) aplica os conceitos básicos do Spring ao desenvolvimento de soluções de mensagens baseadas em Kafka. Ele fornece um "modelo" como uma abstração de alto nível para envio de mensagens. Ele também fornece suporte para POJOs acionados por mensagens com anotações @KafkaListener e um "contêiner de ouvinte". Essas bibliotecas promovem o uso de injeção de dependência e declarativa. Em todos esses casos, você verá semelhanças com o suporte JMS no Spring Framework e o suporte RabbitMQ no Spring AMQP.
- KafkaTemplate
- KafkaMessageListenerContainer
- @KafkaListener
- KafkaTransactionManager
- spring-kafka-test jar with embedded kafka server

### Spring LDAP
Spring LDAP é uma biblioteca para simplificar a programação LDAP em Java, construída sobre os mesmos princípios do Spring Jdbc.

A classe LdapTemplate encapsula todo o trabalho de encanamento envolvido na programação LDAP tradicional, como criação, loop por meio de NamingEnumerations, tratamento de exceções e limpeza de recursos. Isso deixa o programador para lidar com as coisas importantes - onde encontrar dados (DNs e Filtros) e o que fazer com eles (mapear de e para objetos de domínio, vincular, modificar, desvincular etc.), da mesma forma que JdbcTemplate alivia o programador de tudo, exceto o SQL real e como os dados são mapeados para o modelo de domínio.

Além disso, o Spring LDAP fornece conversão de exceção de NamingExceptions para uma hierarquia de exceção não verificada, bem como vários utilitários para trabalhar com filtros, caminhos e atributos LDAP.

### Spring Shell
Os usuários do projeto Spring Shell podem facilmente construir um aplicativo shell completo (também conhecido como linha de comando) dependendo dos jars do Spring Shell e adicionando seus próprios comandos (que vêm como métodos em spring beans). Criar um aplicativo de linha de comando pode ser útil, por exemplo. para interagir com a API REST do seu projeto ou para trabalhar com conteúdo de arquivo local.
- Um modelo de programação simples e orientado a anotações para contribuir com comandos personalizados
- Uso da funcionalidade de configuração automática do Spring Boot como base para uma estratégia de plug-in de comando
- Preenchimento de tabulação, colorização e execução de script
- Personalização do prompt de comando, nome do arquivo de histórico do shell, tratamento de resultados e erros
- Ativação dinâmica de comandos com base em critérios específicos de domínio
- Integração com a API de validação de bean
- Comandos já integrados, como clear screen, gorgeous help, exit
- Tabelas de arte ASCII, com formatação, alinhamento, bordas sofisticadas, etc.

### Spring Statemachine
Spring Statemachine é uma estrutura para desenvolvedores de aplicativos usarem conceitos de máquina de estado com aplicativos Spring.
- Máquina de estado plana de um nível fácil de usar para casos de uso simples.
- Estrutura de máquina de estado hierárquica para facilitar a configuração de estado complexa.
- Regiões de máquina de estado para fornecer configurações de estado ainda mais complexas.
- Uso de gatilhos, transições, guardas e ações.
- Tipo adaptador de configuração segura.
- Padrão do construtor para fácil instanciação para uso fora do contexto do aplicativo Spring
- Receitas para casos de uso usuais
- Máquina de estado distribuída baseada em um Zookeeper
- Ouvintes de eventos da máquina de estado.
- Modelagem UML Eclipse Papyrus.
- Armazene a configuração da máquina em um armazenamento persistente.
- Integração Spring IOC para associar beans a uma máquina de estado.

### Spring Vault
O Spring Vault fornece abstrações familiares do Spring e suporte do lado do cliente para acessar, armazenar e revogar segredos. Ele oferece abstrações de baixo e alto nível para interagir com o Vault, liberando o usuário de preocupações de infraestrutura.

Com o HashiCorp's Vault, você tem um local central para gerenciar dados secretos externos para aplicativos em todos os ambientes. O Vault pode gerenciar segredos estáticos e dinâmicos, como dados de aplicativos, nome de usuário/senha para aplicativos/recursos remotos e fornecer credenciais para serviços externos, como MySQL, PostgreSQL, Apache Cassandra, Consul, AWS e muito mais.
- Suporte à configuração do Spring usando classes @Configuration baseadas em Java.
- Classe auxiliar VaultTemplate que aumenta a produtividade realizando operações comuns do Vault. Inclui mapeamento de objetos integrado entre documentos e POJOs.
- Mecanismos de autenticação suportados: Token; AppRole; AWS-EC2; AWS-IAM; Azure MSI; Certificates (PKI); Cubbyhole; GCP-GCE; GCP-IAM; Kubernetes; Pivotal CloudFoundry
- Integração @VaultPropertySource baseada em anotação
- Suporte para segredos renováveis e rotativos
- Mapeamento de objetos ricos em recursos integrado ao serviço de conversão do Spring
- Metadados de mapeamento baseados em anotações, mas extensíveis para suportar outros formatos de metadados
- Implementação automática de interfaces de repositório, incluindo suporte para métodos de consulta personalizados.

### Spring Web Flow
O Spring Web Flow se baseia no Spring MVC e permite implementar os "fluxos" de um aplicativo da web. Um fluxo encapsula uma sequência de etapas que orientam um usuário pela execução de alguma tarefa de negócios. Ele abrange várias solicitações HTTP, tem estado, lida com dados transacionais, é reutilizável e pode ser dinâmico e de longa duração por natureza.

O ponto ideal para o Spring Web Flow são os aplicativos da Web stateful com navegação controlada, como check-in para um voo, solicitação de empréstimo, checkout de carrinho de compras ou até mesmo adicionar uma etapa de confirmação a um formulário. O que esses cenários têm em comum é uma ou mais das seguintes características:
- Há um começo claro e um ponto final.
- O usuário deve passar por um conjunto de telas em uma ordem específica.
- As alterações não são finalizadas até a última etapa.
- Depois de concluído, não deve ser possível repetir uma transação acidentalmente
O Spring Web Flow fornece uma linguagem de definição de fluxo declarativa para criar fluxos em um nível mais alto de abstração. Ele permite que ele seja integrado a uma ampla variedade de aplicativos sem nenhuma alteração (no modelo de programação de fluxo), incluindo Spring MVC, JSF e até aplicativos da Web Portlet. A seguir estão problemas comuns observados em aplicativos da Web com estado com requisitos de navegação:
- Visualizar o fluxo é muito difícil.
- O aplicativo tem muito código acessando a sessão HTTP.
- Reforçar a navegação controlada é importante, mas não é possível.
- O suporte adequado ao botão Voltar do navegador parece inatingível.
- O navegador e o servidor ficam fora de sincronia com o uso do botão "Voltar".
- Várias guias do navegador causam problemas de simultaneidade com os dados da sessão HTTP.
- O Spring Web Flow fornece uma solução para os problemas acima.

### Spring Web Services
Spring Web Services (Spring-WS) é um produto da comunidade Spring focado na criação de serviços da Web orientados a documentos. O Spring Web Services visa facilitar o desenvolvimento de serviços SOAP com contrato em primeiro lugar, permitindo a criação de serviços web flexíveis usando uma das muitas maneiras de manipular cargas XML. O produto é baseado no próprio Spring, o que significa que você pode usar os conceitos do Spring, como injeção de dependência, como parte integrante do seu serviço da Web.

As pessoas usam o Spring-WS por vários motivos, mas a maioria é atraída por ele depois de descobrir que faltam pilhas SOAP alternativas quando se trata de seguir as práticas recomendadas de serviço da Web. O Spring-WS torna a melhor prática uma prática fácil. Isso inclui práticas como o perfil básico do WS-I, desenvolvimento Contract-First e ter um acoplamento fraco entre contrato e implementação. Os outros recursos principais dos serviços da Web Spring são:
- Torna a melhor prática uma prática fácil: o Spring Web Services facilita a aplicação das melhores práticas. Isso inclui práticas como o perfil básico do WS-I, desenvolvimento Contract-First e ter um acoplamento fraco entre contrato e implementação.
- Mapeamentos poderosos: você pode distribuir a solicitação XML de entrada para qualquer objeto, dependendo da carga útil da mensagem, do cabeçalho da ação SOAP ou de uma expressão XPath.
- Suporte a API XML: As mensagens XML recebidas podem ser tratadas em APIs JAXP padrão, como DOM, SAX e StAX, mas também JDOM, dom4j, XOM ou mesmo tecnologias de marshalling.
- Flexibilidade XML Marshalling: O módulo Object/XML Mapping na distribuição Spring Web Services suporta JAXB 1 e 2, Castor, XMLBeans, JiBX e XStream. E por ser um módulo separado, você também pode usá-lo em código de serviços não Web.
- Reutiliza sua experiência em Spring: O Spring-WS usa contextos de aplicativos Spring para todas as configurações, o que deve ajudar os desenvolvedores Spring a se atualizarem de maneira agradável e rápida. Além disso, a arquitetura do Spring-WS se assemelha à do Spring-MVC.
- Suporta WS-Security: O WS-Security permite que você assine mensagens SOAP, as criptografe e descriptografe ou autentique-as.
- Integra-se com o Acegi Security: A implementação do WS-Security do Spring Web Services fornece integração com o Spring Security. Isso significa que você também pode usar sua configuração existente para seu serviço SOAP.
- Construído pelo Maven: Isso ajuda você a reutilizar efetivamente os artefatos do Spring Web Services em seus próprios projetos baseados em Maven.
- Licença Apache. Você pode usar o Spring-WS com confiança em seu projeto.


## REFERÊNCIAS
- https://www.devmedia.com.br/exemplo/como-comecar-com-spring/73
- https://docs.spring.io/spring-framework/docs/4.3.x/spring-framework-reference/html/overview.html

![Green Flow](~Logo.png)

# Green Flow - Monitoramento de Consumo de Energia

Vídeo apresentação no YouTube: https://youtu.be/PeL16VG2M8w
<br>
Simulação no Wokwi: https://wokwi.com/projects/415204779915356161

## Introdução

Este projeto tem como objetivo monitorar o consumo de energia elétrica em tempo real, ajudando residências e pequenos negócios a evitar desperdícios e reduzir custos. A solução permite identificar momentos de consumo elevado e enviar alertas para que os usuários possam ajustar seus hábitos e economizar energia.

O projeto foi desenvolvido utilizando o simulador Wokwi, que emula um ESP32 com comunicação MQTT, proporcionando uma interface amigável para visualizar o consumo em tempo real.

## Funcionalidades

- **Monitoramento Contínuo:** Leitura e monitoramento contínuo do consumo de energia elétrica.
- **Alertas de Consumo:** LEDs e buzzer indicam quando o consumo atinge limites elevados ou críticos.
- **Comunicação MQTT:** O ESP32 envia os dados para um broker MQTT em dois tópicos diferentes:
  - **`energia/consumo`**: Envia leituras do consumo em tempo real.
  - **`energia/alerta`**: Envia alertas quando o consumo está elevado ou crítico.

## Estrutura do Projeto

O projeto está dividido em componentes principais:

1. **ESP32 e Simulação no Wokwi**: Utilizando o ESP32 para coletar dados do sensor de corrente e controlar LED e buzzer.
2. **Comunicação MQTT**: Utiliza a biblioteca `PubSubClient` para comunicação MQTT e envio dos dados para um broker (como Mosquitto).
3. **Dashboard no Node-RED**: Visualização em tempo real dos dados enviados pelo ESP32.
4. **README Detalhado**: Um README que descreve como executar o projeto, dependências e como configurá-lo no simulador Wokwi.

## Componentes Utilizados

- **Sensor de Corrente Elétrica**: Simulado para calcular o consumo em amperes.
- **LED Indicador**: Sinaliza quando o consumo está elevado.
- **Buzzer**: Alarmar quando o consumo atingir um nível crítico.
- **ESP32**: Para controlar os sensores e atuadores e fazer a comunicação MQTT.

## Resultados Esperados e Impacto

### Resultados Esperados

- Monitoramento constante do consumo elétrico.
- Alertas em tempo real para notificar o usuário sobre consumo elevado ou crítico.
- Identificação de equipamentos com alto consumo energético, permitindo ajustes para reduzir o desperdício.

### Impacto

- **Economia de Energia**: Redução dos custos de energia em residências e pequenas empresas.
- **Conscientização**: Aumenta a consciência sobre o uso eficiente de energia.
- **Sustentabilidade**: Contribui para práticas sustentáveis e redução da pegada de carbono.

## Como Executar o Projeto

1. **Clonar o Repositório GitHub**: Clone o repositório do projeto que contém o código fonte e as dependências.
2. **Instalar Dependências**: Utilize o Arduino IDE ou PlatformIO para instalar as bibliotecas necessárias (`PubSubClient`, `WiFi`, `LiquidCrystal_I2C`).
3. **Simulação no Wokwi**: Abra o simulador Wokwi e carregue o projeto para visualizar o comportamento do ESP32 em tempo real.
4. **Configurar o Broker MQTT**: Configure um broker (por exemplo, Mosquitto) para receber os dados do ESP32.
5. **Visualizar no Node-RED**: Configure um dashboard Node-RED para visualizar os dados e alertas em tempo real.

<article>
        <h2>Integrantes</h2>
                <h3><img src="https://avatars.githubusercontent.com/u/129889380?v=4" width="50px" alt="Pedro Guidotte Icon">  Pedro Guidotte | RM556630<a href="https://github.com/peguidotte" target="_blank" style="font-style: italic">  /GitHub <i class="fab fa-github"></i></a>
                <a href="https://www.linkedin.com/in/pedro-guidotte/" target="_blank" style="font-style: italic">  /LinkedIn<i class="fab fa-linkedin"></i></a></h3>
                <h3><img src="https://avatars.githubusercontent.com/u/158540749?v=4)" width="50px" alt="Gabriel Vara Icon">  Gabriel Vara | RM555355<a href="https://github.com/gabrielvara" target="_blank" style="font-style: italic"> 
 /GitHub <i class="fab fa-github"></i></a>
                <a href="https://www.linkedin.com/in/gabriel-vara" target="_blank" style="font-style: italic">  /LinkedIn <i class="fab fa-linkedin"></i></a></h3>
                <h3><img src="https://avatars.githubusercontent.com/u/158527393?v=4" width="50px" alt="Leonardo Correa Icon">  Leonardo Correa | RM555573<a href="https://github.com/leocorreamello" target="_blank" style="font-style: italic">  /GitHub <i class="fab fa-github"></i></a>
                <a href="https://www.linkedin.com/in/leocorreamello/" target="_blank" style="font-style: italic">  /LinkedIn <i class="fab fa-linkedin"></i></a></h3>
</article>

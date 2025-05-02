# 🚦 Semáforo com faixa de Pedestre com AVR e Arduino
Este projeto consiste no desenvolvimento de um circuito com programação em AVR para controlar um tráfego (semáforo), a ser instalado em um cruzamento de pedestre. O funcionamento é o seguinte:

*Comportaemnto do circuito:*

Intervalo de tempo para o Semáforo de Veículos(sv):
Verde: 42s
Amarelo: 3s
Vermelho: 15s

Semáforo de Pedestre(sp) sincronizado com o de veículos:
Verde (VDS) : Vermelho (VMP)
Amarelo (AS) : Vermelho (VMP)
Vermelho (VMS) : Verde (VDP)

Piscar Vermelho (VMP) 3x antes de mudar em definitivo.

Botão pulsador para antecipar liberação de passagem dos pedestres:
Se faltar mais do que 10s para o acionamento da cor amarela, reduzir para 10s.
Se faltar menos do que 10s para o acionamento da cor amarela, manter o tempo restante


🛠 Tecnologias e Componentes Utilizados:

| Componente            | Modelo                                                                                                                               | Descrição                                                                                                                                     |
| :-------------------- | :----------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------- |
| Microcontrolador      | [AVR - ATMega328P](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf) | Plataforma Arduino Uno como interface                                                                                                         |
| IDE                   | [MPLabX](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)                                                        | Ambiente de Desenvolvimento Integrado - [Instalação](https://developerhelp.microchip.com/xwiki/bin/view/software-tools/ides/x/install-guide/) |
| Compilador            | [XC8](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/xc8)                                                | [Instalação](https://developerhelp.microchip.com/xwiki/bin/view/software-tools/xc8/install/)                                                  |
| Editor de código      | [Visual Studio Code](https://code.visualstudio.com/)                                                                                | [v1.97.2](https://code.visualstudio.com/sha/download?build=stable&os=win32-x64-user)                         |
| Construtor de projeto | [Makefile](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows)                                      | Power Shell<br>`winget install Chocolatey.Chocolatey`<br>`choco install make`                                                                 |
| Gravador do AVR       | [AVRDudess](https://github.com/ZakKemble/AVRDUDESS/releases/tag/v2.18)                                                               | [ZakKemble/AVRDUDESS/v2.18](https://github.com/ZakKemble/AVRDUDESS/releases/download/v2.18/AVRDUDESS-2.18-setup.exe)                          |
| Simulador eletrônico  | [SimulIDE](https://simulide.com/p/downloads/)                                                                                        | Power Shell<br>`winget install SimulIDE.SimulIDE`                                                                                             |
| Versionamento         | [git](https://git-scm.com/downloads)                                                                                                 | Power Shell<br>`winget install --id Git.Git -e --source winget`                                                                               |

Este projeto faz parte de uma atividade acadêmica e tem como objetivo a aplicação prática de conceitos de eletrônica e programação embarcada.

🗺️ Mapa de entradas e saídas:

| Função  | Dispositivo   | Descrição                         | Pino (Arduino Uno) | Pino (ATmega328P) | PORT |
| :------ | :------------ | :-------------------------------- | :----------------- | :-----------------|:-----|
| Entrada | Botão      | Desliga sistema de comando       | 8                  | 15                | PB1  |
| Saída   | K1            | Contator K1                       | 9                 | 16                | PB5  |
| Saída | Botão S1      | Liga sistema de comando          | 10                 | 17                | PB2  |
| Saída   | K3            | Contator K3                       | 11                 | 18                | PB3  |
| Saída   | K2            | Contator K2                       | 12                 | 19                | PB4  |
| Saída   | K1            | Contator K1                       | 13                 | 20                | PB5  |



| 🚦 Simulação no SimulIDE: |
|:----------------------------------------------------------------:|
| ![EstrelaTriangulo](EstrelaTriangulo.gif)                                   |

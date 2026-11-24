# Testes do monitoramento de temperatura (IoT)

## Objetivo
Verificar se o circuito indica corretamente o estado da temperatura da sala de servidores usando três LEDs.

## Configuração
- Placa: Arduino Uno
- Sensor: TMP36 (pino A0)
- LEDs: verde (pino 2), amarelo (pino 3), vermelho (pino 4), cada um com resistor de 220 Ω
- Limites: normal até 26 °C, atenção de 27 a 30 °C, crítico a partir de 31 °C
- Ambiente: simulação no Tinkercad Circuits

## Como os testes foram feitos
Com a simulação rodando, a temperatura do sensor foi alterada pelo controle deslizante do Tinkercad. Em cada cenário, observou-se qual LED acendeu.

## Resultados

| Cenário | Temperatura aplicada | Comportamento esperado | Resultado obtido |
|---|---|---|---|
| Normal | 22 °C | Só o LED verde acende | Verde aceso, amarelo e vermelho apagados |
| Normal (limite) | 26 °C | Só o LED verde acende | Verde aceso, amarelo e vermelho apagados |
| Atenção (início) | 27 °C | Só o LED amarelo acende | Amarelo aceso, verde e vermelho apagados |
| Atenção | 29 °C | Só o LED amarelo acende | Amarelo aceso, verde e vermelho apagados |
| Atenção (limite) | 30 °C | Só o LED amarelo acende | Amarelo aceso, verde e vermelho apagados |
| Crítico (início) | 31 °C | Só o LED vermelho acende | Vermelho aceso, verde e amarelo apagados |
| Crítico | 35 °C | Só o LED vermelho acende | Vermelho aceso, verde e amarelo apagados |

## Evidências
- Circuito: `circuito.png`
- Simulação: ver `link-tinkercad.txt`

## Conclusão
O circuito respondeu como esperado nos três níveis. Os LEDs mudam de verde para amarelo a partir de 27 °C e de amarelo para vermelho a partir de 31 °C, indicando normal, atenção e crítico.

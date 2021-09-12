#include "perceptron.hpp"


// Constant values
const int ECHO_PIN = 5;
const int TRIGGER_PIN = 6;
const int RED_LED_PIN = 11;
const int GREEN_LED_PIN = 12;

// Variables
float distance;
long time;


// Create perceptron model with one input
Perceptron perceptron(1);


// Traing the perceptron
void train()
{
    int distance_step = 5;

    // Train for 160 epochs
    for (int epoch = 0; epoch < 160; epoch++)
    {
        for (int d = 0; d < 340; d += distance_step)
        {
            // Set the input in the model
            perceptron.inputs[0] = d;

            // Make a prediction
            int prediction = perceptron.feed_forward();

            if ((d <= 150 && prediction == -1) || (d > 150 && prediction == 1))
            {
                perceptron.train(-prediction, prediction);
            }
        }
    }
}


void setup()
{
    Serial.begin(9600);

    // Init pin modes
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

    // Train the model before run in loop
    train();
}


void loop()
{
    // Send a pulse to activate the the sensor
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    // Measure response pulse
    time = pulseIn(ECHO_PIN, HIGH) / 2;

    // Compute the distance between in cm
    // d = v * t
    // Sound speed = 343 m/s
    // Time in microseconds
    distance = float(time * 0.0343);
    Serial.print("Distance: ");
    Serial.println(distance);

    // Set the input in the model
    perceptron.inputs[0] = distance;

    // Classification
    int prediction = perceptron.feed_forward();

    Serial.print("Prediction: ");
    Serial.println(prediction);

    if (prediction == - 1)
    {
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(RED_LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(GREEN_LED_PIN, HIGH);
        digitalWrite(RED_LED_PIN, LOW);
    }

    delay(1000);
}

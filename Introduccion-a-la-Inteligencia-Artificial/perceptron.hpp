class Perceptron
{
public:
    // Inputs vector
    float* inputs;

    /** Perceptron constructor
     * 
     * Inputs:
     *      int ninputs - number if inputs
     */
    Perceptron(int ninputs)
    {
        // Default learning rate
        this->alpha = 0.001;
        // Set tthe number of inputs
        this->n = ninputs + 1;

        // Asking for memory
        this->inputs = new float[n];
        this->weights = new float[n];

        // Init bias
        this->inputs[this->n - 1] = 1;
        // Init random weights
        this->randomize();
    }

    /**
     * Random weights
     */
    void randomize()
    {
        for (int i = 0; i < n; i++)
        {
            this->weights[i] = (float) random(-1000, 1000) / 1000.0;
        }
    }

    /**
     * Traning function
     * 
     * Inputs:
     *      target - target value
     *      prediction - predicted value
     */
    void train(int target, float prediction)
    {
        float error = target - prediction;

        // Update weights
        for (int i = 0; i < this->n; i++)
        {
            this->weights[i] += this->alpha * error * this->inputs[i];
        }
    }

    /**
     * Forward function
     */
    int feed_forward()
    {
        float sum = 0.0;

        for (int i = 0; i < this->n; i++)
        {
            sum += inputs[i] * this->weights[i];
        }

        return this->activate(sum);
    }
private:
    // Random weights vector
    float* weights;
    // Inputs number
    int n;
    // Learning rate
    float alpha;

    /**
     * Activation function
    */
    int activate(float sum)
    {
        // Signum function
        return (sum >= 0.0) ? 1 : -1;
    }
};

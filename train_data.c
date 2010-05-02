#include "train_data.h"

TD *create_train_data(unsigned int inputs, unsigned int outputs) {
    TD *data = (TD *)malloc(sizeof(TD));
    data->input = NULL;
    data->output = NULL;
    data->data_count = 0;
    data->input_count = inputs;
    data->output_count = outputs;
    return data;
}

void destroy_train_data(TD *data) {
    free(data->input);
    free(data->output);
    free(data);
}

void add_train_data(TD *data, float *input, float *output) {
    data->data_count++;

    // set input data
    data->input = (float **)realloc(data->input, sizeof(float *) * data->data_count);
    data->input[data->data_count - 1] = (float *)malloc(sizeof(float) * data->input_count);
    memcpy(data->input[data->data_count - 1], input, sizeof(float) * data->input_count);
    //~ data->input[data->data_count - 1][0] = 0.5;
    //~ data->input[data->data_count - 1][1] = 0.25;
    

    // set output data
    data->output = (float **)realloc(data->output, sizeof(float *) * data->data_count);
    data->output[data->data_count - 1] = (float *)malloc(sizeof(float) * data->output_count);
    memcpy(data->output[data->data_count - 1], output, sizeof(float) * data->output_count);
    //~ data->output[data->data_count - 1][0] = 0.5;
    //~ data->output[data->data_count - 1][1] = 0.25;
}
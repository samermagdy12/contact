from flask import Flask, request, jsonify, render_template
import pickle
import numpy as np

# Load the trained model (assuming it's a pickle file)
with open('best_model.pkl', 'rb') as model_file:
    model = pickle.load(model_file)

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/predict', methods=['POST'])
def predict():
    try:
        # Print form data for debugging
        print(request.form)

        # Extract features from the form
        float_features = [
            float(request.form['number_of_adults']),
            float(request.form['number_of_children']),
            float(request.form['number_of_weekend_nights']),
            float(request.form['number_of_week_nights']),
            int(request.form['type_of_meal']),
            int(request.form['room_type']),
            float(request.form['lead_time']),
            float(request.form['market_segment_type']),
            float(request.form['average_price']),
            float(request.form['special_requests']),
            float(request.form['car_parking_space']),  # New field
            float(request.form['repeated']),  # New field
            float(request.form['P-C']),  # New field
            float(request.form['P-not-C'])   # New field
        ]
        features = [np.array(float_features)]
        prediction = model.predict(features)[0]

        if prediction == 0:
            prediction_text = "The booking status is canceled"
        else:
            prediction_text = "The booking status is not canceled"
        
        return jsonify({'prediction': prediction_text})
    except KeyError as e:
        return jsonify({'error': f'Missing form field: {str(e)}'}), 400

if __name__ == "__main__":
    app.run(debug=True)

import json
import requests

def read_binary_file(file_path):
    with open(file_path, 'rb') as binary_file:
        binary_data = binary_file.read()
    return binary_data

def convert_binary_to_json(binary_data):
    def safe_decode(data, encoding='utf-8'):
        try:
            return data.decode(encoding).rstrip('\0')
        except UnicodeDecodeError:
            return data.decode(encoding, errors='replace').rstrip('\0')

    # Assuming the binary data represents a single record with the given structure
    personal_info_size = 100  # Adjust the size based on the actual structure
    employment_info_size = 40
    financial_info_size = 20
    account_details_size = 40
    transaction_history_size = 40

    personal_info = {
        'fullName': safe_decode(binary_data[:30]),
        'dateOfBirth': safe_decode(binary_data[30:40]),
        'gender': safe_decode(binary_data[40:45]),
        'nationality': safe_decode(binary_data[45:55]),
        'residentialAddress': safe_decode(binary_data[55:95]),
        'contactInfo': {
            'phoneNumber': safe_decode(binary_data[95:105]),
            'email': safe_decode(binary_data[105:130])
        }
    }

    employment_info = {
        'employmentStatus': safe_decode(binary_data[130:140]),
        'employerName': safe_decode(binary_data[140:180]),
        'jobTitle': safe_decode(binary_data[180:210]),
        'monthlyIncome': int.from_bytes(binary_data[210:214], byteorder='big')
    }

    financial_info = {
        'annualIncome': int.from_bytes(binary_data[214:218], byteorder='big'),
        'sourceOfIncome': safe_decode(binary_data[218:228])
    }

    account_details = {
        'accountNumber': safe_decode(binary_data[228:238]),
        'accountType': safe_decode(binary_data[238:248]),
        'accountOpeningDate': safe_decode(binary_data[248:258]),
        'accountBalance': int.from_bytes(binary_data[258:262], byteorder='big')
    }

    # Assuming only one transaction in the history
    transaction_history = [
        {
            'type': safe_decode(binary_data[262:272]),
            'amount': int.from_bytes(binary_data[272:276], byteorder='big'),
            'timeStamp': safe_decode(binary_data[276:286]),
            'payee': safe_decode(binary_data[286:316]),
            'payer': safe_decode(binary_data[316:346])
        }
    ]

    result = {
        'personalInfo': personal_info,
        'employmentInfo': employment_info,
        'financialInfo': financial_info,
        'accountDetails': account_details,
        'transactionHistory': transaction_history
    }

    return json.dumps(result, indent=2)

def send_to_api(json_data, api_url):
    headers = {'Content-Type': 'application/json'}
    response = requests.post(api_url, data=json_data, headers=headers)

    if response.status_code == 200:
        print(response.text)
    else:
        print(f"Failed to send data. Status code: {response.status_code}")
        print(response.text)

if __name__ == "__main__":
    # Replace 'your_file.bin' with the actual binary file path
    binary_file_path = 'bank.bin'

    # Replace 'https://your-api-endpoint.com' with the actual API endpoint
    api_url = 'http://localhost:4520/api/create-account'

    binary_data = read_binary_file(binary_file_path)
    json_data = convert_binary_to_json(binary_data)
    send_to_api(json_data, api_url)

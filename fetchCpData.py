import requests
import time
import hashlib
import random
import string
import base64
import json

key = ""
secret = ""


def generate_api_signature(method, params, secret):
    """
    Generate Codeforces API signature.
    
    Args:
        method: API method name (e.g., 'user.status')
        params: Dictionary of parameters (excluding apiSig)
        secret: API secret key
    
    Returns:
        tuple: (apiSig, params_with_auth) - signature string and updated params dict
    """
    # Generate random 6-character string
    rand = ''.join(random.choices(string.ascii_lowercase + string.digits, k=6))
    
    # Add apiKey and time to parameters
    params['apiKey'] = key
    params['time'] = int(time.time())
    
    # Sort parameters lexicographically by key, then by value
    sorted_params = sorted(params.items())
    
    # Build the query string for hashing
    query_string = "&".join([f"{k}={v}" for k, v in sorted_params])
    
    # Build the string to hash: rand/method?param1=value1&...#secret
    hash_string = f"{rand}/{method}?{query_string}#{secret}"
    
    # Generate SHA-512 hash and convert to hex
    hash_hex = hashlib.sha512(hash_string.encode()).hexdigest()
    
    # Signature is rand + hash
    api_sig = rand + hash_hex
    
    return api_sig, params


def make_codeforces_request(method, **params):
    """
    Make an authenticated request to Codeforces API.
    
    Args:
        method: API method name (e.g., 'user.status', 'contest.hacks')
        **params: Additional parameters for the API call
    
    Returns:
        dict or list: JSON response from the API
    """
    # Generate signature
    api_sig, auth_params = generate_api_signature(method, params, secret)
    auth_params['apiSig'] = api_sig
    
    # Build URL
    url = f"https://codeforces.com/api/{method}"
    
    # Make request
    response = requests.get(url, params=auth_params)
    response.raise_for_status()
    
    return response.json()


def decode_source_code(submission):
    """
    Extract and decode the Base64 encoded source code from a submission.
    
    Args:
        submission: A single submission object from the API response
    
    Returns:
        str: The decoded source code
    """
    if 'sourceBase64' in submission:
        encoded = submission['sourceBase64']
        decoded = base64.b64decode(encoded).decode('utf-8')
        return decoded
    return None


def extract_submission_details(submission):
    """
    Extract key details from a submission including decoded source code.
    
    Args:
        submission: A single submission object from the API response
    
    Returns:
        dict: Dictionary with submission details and decoded source code
    """
    details = {
        'id': submission.get('id'),
        'problem': submission['problem']['name'],
        'problem_index': submission['problem']['index'],
        'verdict': submission.get('verdict'),
        'programming_language': submission.get('programmingLanguage'),
        'time_consumed_ms': submission.get('timeConsumedMillis'),
        'memory_consumed_bytes': submission.get('memoryConsumedBytes'),
        'passed_tests': submission.get('passedTestCount'),
        'source_code': decode_source_code(submission)
    }
    return details


def display_submissions_with_code(handle, from_id=1, count=5):
    """
    Fetch and display user submissions with their decoded source code.
    
    Args:
        handle: Codeforces username
        from_id: Starting submission index (1-based)
        count: Number of submissions to fetch
    """
    try:
        result = make_codeforces_request(
            'user.status',
            handle=handle,
            **{'from': from_id, 'count': count, 'includeSources': 'true'}
        )
        
        if result['status'] == 'OK':
            submissions = result['result']
            for idx, submission in enumerate(submissions, 1):
                details = extract_submission_details(submission)
                
                print(f"\n{'='*80}")
                print(f"Submission #{idx}")
                print(f"{'='*80}")
                print(f"ID: {details['id']}")
                print(f"Problem: {details['problem']} ({details['problem_index']})")
                print(f"# Tags: {submission['problem']['tags']}")
                print(f"Verdict: {details['verdict']}")
                print(f"Language: {details['programming_language']}")
                print(f"Time: {details['time_consumed_ms']}ms | Memory: {details['memory_consumed_bytes']} bytes")
                print(f"Passed Tests: {details['passed_tests']}")
                print(f"\nSource Code:\n{'-'*80}")
                print(details['source_code'])
                print(f"{'-'*80}\n")
                
                if (details['verdict'] == "OK"):
                    with open(f"{details['problem_index']}_{details['problem'].replace(' ', '_')}.cpp", "w") as f:
                        f.write(f"/*\n\nProblem Tags: {submission['problem']['tags']} \n\n*/\n\n")
                        f.write(details['source_code'])
        else:
            print("Error fetching submissions")
            
    except Exception as e:
        print(f"Error: {e}")


# Example usage:
if __name__ == "__main__":
    try:
        # Display submissions with decoded source code
        display_submissions_with_code('UB2002', from_id=1, count=1000)
        
    except Exception as e:
        print(f"Error: {e}")
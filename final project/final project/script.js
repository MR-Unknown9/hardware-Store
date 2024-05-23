document.getElementById('register-form').addEventListener('submit', function(event) {
    event.preventDefault(); 
 
    var emailInput = document.getElementById('email').value;
  

    var emailPattern = /^[^\s@]+@gmail\.com$/;
  
 
    var emailIsValid = emailPattern.test(emailInput);
  
  
    if (!emailIsValid) {
      alert('Please enter a valid email address.');
      return;
    }
  
    alert('Registration successful!');
  
  
    var backButton = document.createElement('button');
    backButton.textContent = 'Back to Login';
    backButton.addEventListener('click', function() {
      window.location.href = 'login.html'; 
    });
  
   
    document.getElementById('register-form').appendChild(backButton);
  });
  
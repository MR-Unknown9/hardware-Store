document.querySelector('form').addEventListener('submit', function(event) {
  event.preventDefault(); 
  
  var emailInput = document.querySelector('input[type="email"]').value;

  var emailPattern = /^[^\s@]+@gmail\.com$/;

  var emailIsValid = emailPattern.test(emailInput);

  if (!emailIsValid) {
    alert('Please enter a valid Gmail address.');
    return;
  }

  alert('Login successful!');

  window.location.href = 'booking.html';
});

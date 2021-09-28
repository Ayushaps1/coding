var weather = {
    apikey: "530c9464b565c27bd206fe4e225ea997",
    fetchweather: function (city) {
        fetch(
            "https://api.openweathermap.org/data/2.5/weather?q=" 
            + city 
            + "&units=metric&appid=" 
            + this.apikey
        )
        .then((response) => response.json())
        .then((data) => this.displayWeather(data))
    },
    displayWeather: function(data){
        const{ name } = data;
        const{ icon, description } = data.weather[0];
        const{ temp, humidity } = data.main;
        const{ speed } = data.wind;
        document.querySelector(".city").innerHTML = "Weather in " + name;
        document.querySelector(".temp").innerHTML = temp + "°C";
        document.querySelector("img").src = "http://openweathermap.org/img/wn/" + icon +".png";
        document.querySelector(".description").innerHTML = description;
        document.querySelector(".humidity").innerHTML = "Humidity: " + humidity + "%";
        document.querySelector(".wind").innerHTML = "Wind Speed: " + speed + "km/h";
        document.querySelector(".weather").classList.remove("loading");
        document.querySelector("body").classList.remove("foranimation");
        document.body.style.backgroundImage = "url('https://source.unsplash.com/1600x900/?"+name+"')";
    },
    search: function(){
        this.fetchweather(document.querySelector(".search-box").value);
    }
};

var geocode = {
    reverseGeocode: function (latitude,longitude){
        var api_key = '82328e64be7f47a3aea7f619560449f2';
        
        var api_url = 'https://api.opencagedata.com/geocode/v1/json'
      
        var request_url = api_url
          + '?'
          + 'key=' + api_key
          + '&q=' + encodeURIComponent(latitude + ',' + longitude)
          + '&pretty=1'
          + '&no_annotations=1';
      
        // see full list of required and optional parameters:
        // https://opencagedata.com/api#forward
      
        var request = new XMLHttpRequest();
        request.open('GET', request_url, true);
      
        request.onload = function() {
          // see full list of possible response codes:
          // https://opencagedata.com/api#codes
      
          if (request.status === 200){ 
            // Success!
            var data = JSON.parse(request.responseText);
            weather.fetchweather(data.results[0].components.city);
      
          } else if (request.status <= 500){ 
            // We reached our target server, but it returned an error
                                 
            console.log("unable to geocode! Response code: " + request.status);
            var data = JSON.parse(request.responseText);
            console.log('error msg: ' + data.status.message);
          } else {
            console.log("server error");
          }
        };
      
        request.onerror = function() {
          // There was a connection error of some sort
          console.log("unable to connect to server");        
        };
      
        request.send();  // make the request
               
    },

    getlocation: function(){
        function success (data){
            geocode.reverseGeocode(51,7);
        }

        if(navigator.geolocation){
            navigator.geolocation.getCurrentPosition(success,console.error);
        }
        else{
            weather.fetchweather("denver");
        }
    }
    
};

document.querySelector(".search button").addEventListener("click",function(){
    weather.search();
});

document.querySelector(".search-box").addEventListener("keyup",function(event){
    if(event.key == "Enter"){
        weather.search();
    } 
});

geocode.getlocation();

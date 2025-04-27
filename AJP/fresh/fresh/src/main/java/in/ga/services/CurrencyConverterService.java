package in.ga.services;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

@Path("/currency")
public class CurrencyConverterService {
    
    // Hard-coded exchange rates for demonstration
    private static final double USD_TO_EUR = 0.85;
    private static final double USD_TO_GBP = 0.73;
    private static final double USD_TO_INR = 74.50;
    private static final double USD_TO_JPY = 110.25;
    private static final double USD_TO_AUD = 1.32;
    
    @GET
    @Path("/convert")
    @Produces(MediaType.APPLICATION_JSON)
    public Response convertCurrency(
            @QueryParam("amount") double amount,
            @QueryParam("from") String fromCurrency,
            @QueryParam("to") String toCurrency) {
        
        if (amount <= 0) {
            return Response.status(Response.Status.BAD_REQUEST)
                    .entity("{\"error\": \"Amount must be positive\"}")
                    .build();
        }
        
        // For this example, we'll assume all conversions are from USD
        if (!"USD".equalsIgnoreCase(fromCurrency)) {
            return Response.status(Response.Status.BAD_REQUEST)
                    .entity("{\"error\": \"Currently only conversions from USD are supported\"}")
                    .build();
        }
        
        double result;
        String conversion;
        
        switch (toCurrency.toUpperCase()) {
            case "EUR":
                result = amount * USD_TO_EUR;
                conversion = String.format("%.2f USD = %.2f EUR", amount, result);
                break;
            case "GBP":
                result = amount * USD_TO_GBP;
                conversion = String.format("%.2f USD = %.2f GBP", amount, result);
                break;
            case "INR":
                result = amount * USD_TO_INR;
                conversion = String.format("%.2f USD = %.2f INR", amount, result);
                break;
            case "JPY":
                result = amount * USD_TO_JPY;
                conversion = String.format("%.2f USD = %.2f JPY", amount, result);
                break;
            case "AUD":
                result = amount * USD_TO_AUD;
                conversion = String.format("%.2f USD = %.2f AUD", amount, result);
                break;
            case "USD":
                result = amount;
                conversion = String.format("%.2f USD = %.2f USD", amount, result);
                break;
            default:
                return Response.status(Response.Status.BAD_REQUEST)
                        .entity("{\"error\": \"Unsupported target currency: " + toCurrency + "\"}")
                        .build();
        }
        
        // Return JSON response
        String jsonResponse = String.format("{\"conversion\": \"%s\", \"result\": %.2f, \"from\": \"USD\", \"to\": \"%s\"}", 
                              conversion, result, toCurrency.toUpperCase());
        
        return Response.ok().entity(jsonResponse).build();
    }
    
    @GET
    @Path("/rates")
    @Produces(MediaType.APPLICATION_JSON)
    public Response getExchangeRates() {
        String rates = "{\"base\": \"USD\", \"rates\": {" +
                "\"EUR\": " + USD_TO_EUR + "," +
                "\"GBP\": " + USD_TO_GBP + "," +
                "\"INR\": " + USD_TO_INR + "," +
                "\"JPY\": " + USD_TO_JPY + "," +
                "\"AUD\": " + USD_TO_AUD + "}}";
        
        return Response.ok().entity(rates).build();
    }
}
// CarouselActivities.js

import React from 'react';
import Carousel from "react-multi-carousel";
import "react-multi-carousel/lib/styles.css";
import chicoutimiActivities from './Activities';
import './CarouselActivities.css'; // Make sure to import your CSS file

const Button = ({ label, onClick, className }) => {
    return (
        <button className={className} onClick={onClick}>
            {label}
        </button>
    );
};

const CustomCarousel = () => {
    const responsive = {
        superLargeDesktop: {
            // the naming can be any, depends on you.
            breakpoint: { max: 4000, min: 3000 },
            items: 1
        },
        desktop: {
            breakpoint: { max: 3000, min: 1024 },
            items: 1
        },
        tablet: {
            breakpoint: { max: 1024, min: 464 },
            items: 1
        },
        mobile: {
            breakpoint: { max: 464, min: 0 },
            items: 1
        }
    };
    const handleClick = (link) => {
        window.location.href = link
    };
    return (
        <Carousel responsive={responsive} className='carousel-container'>
            {chicoutimiActivities.map((activity) => {
                return (
                    <div className="activity-card">
                        <img src={activity.image} alt={activity.name} className='image' />
                        <h3>{activity.name}</h3>
                        <p>{activity.quickDescription}</p>
                        <Button label="See more" onClick={() => handleClick(activity.link)} className="custom-button" />

                    </div>
                )
            }
            )}
        </Carousel>
    );
};

function CarouselActivities() {
    return (
        <div>
            <CustomCarousel />
        </div>
    );
}

export default CarouselActivities;

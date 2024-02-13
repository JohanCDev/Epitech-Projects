import { render, screen } from '@testing-library/react';
import App4 from './App4';

test('renders learn react link', () => {
  render(<App4 />);
  const linkElement = screen.getByText(/learn react/i);
  expect(linkElement).toBeInTheDocument();
});
